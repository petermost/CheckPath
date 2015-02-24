#include "Util.hpp"
#include <QSet>
#include <QStringList>

QStringList findDuplicates( const QStringList &list ) {
	QStringList duplicates;
	QSet< QString > uniques;

	for ( const QString &s : list ) {
		if ( !uniques.contains( s ))
			uniques.insert( s );
		else
			duplicates.append( s );
	}
	return duplicates;
}

