#include "Util.hpp"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QProcessEnvironment>
#include <pera_software/company/PERA.hpp>

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

	out << pera_software::company::PERA::FULL_NAME << endl;

	QProcessEnvironment environment = QProcessEnvironment::systemEnvironment();
	QStringList searchPath = environment.value( PATH_VARIABLE_NAME ).split( QDir::listSeparator() );
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

	// Show non-existing path from the environment which end with '_HOME':

	searchPath.clear();
	for ( const QString &key : environment.keys() ) {
		if ( key.endsWith( "_HOME", Qt::CaseInsensitive )) {
			QString value = environment.value( key );
			searchPath.append( value );
		}
	}

	missingPaths = findMissingPaths( searchPath );
	if ( missingPaths.isEmpty() )
		out << "No missing '_HOME' paths in environment found." << endl;
	else {
		for ( const QString missingPath : missingPaths )
			err << "Missing '_HOME' path: '" << missingPath << "' in environment found!" << endl;
	}

	return EXIT_SUCCESS;
}
