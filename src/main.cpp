#include "Util.hpp"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QProcessEnvironment>

using namespace std;

QTextStream out( stdout );
QTextStream err( stderr );

static const QString PATH_VARIABLE_NAME = "Path";


QStringList findMissingPaths( const QStringList &paths ) {
	QStringList missingPaths;
	for ( const QString &path : paths ) {
		if ( !QFile::exists( path ))
			missingPaths += path;
	}
	return missingPaths;
}


int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);

	QProcessEnvironment environment = QProcessEnvironment::systemEnvironment();
	QStringList searchPath = environment.value( PATH_VARIABLE_NAME ).split( ';' );
	if ( searchPath.isEmpty() ) {
		err << "Environment variable '" << PATH_VARIABLE_NAME << "' not found!" << endl;
		return EXIT_FAILURE;
	}

	// Show duplicated paths in PATH:

	QStringList duplicatedPaths = findDuplicates( searchPath );
	if ( duplicatedPaths.isEmpty() )
		out << "No duplicated paths in PATH found." << endl;
	else {
		for ( const QString &path : duplicatedPaths )
			err << "Duplicated path '" << path << "' found!" << endl;
	}

	// Show non-existing paths in PATH:

	QStringList missingPaths = findMissingPaths( searchPath );
	if ( missingPaths.isEmpty() )
		out << "No missing paths in PATH found." << endl;
	else {
		for ( const QString nonExistingPath : missingPaths )
			err << "Missing path: '" << nonExistingPath << "' in PATH found!" << endl;
	}

	// Show non-existing path from the environmen which end with '_HOME':

	searchPath.clear();
	for ( const QString &key : environment.keys() ) {
		if ( key.endsWith( "_HOME", Qt::CaseInsensitive )) {
			QString value = environment.value( key );
			searchPath.append( value );
		}
	}

	missingPaths = findMissingPaths( searchPath );
	if ( missingPaths.isEmpty() )
		out << "No missing paths in ENVIRONMENT found." << endl;
	else {
		for ( const QString missingPath : missingPaths )
			err << "Missing path: '" << missingPath << "' in ENVIRONMENT found!" << endl;
	}

	return EXIT_SUCCESS;
}
