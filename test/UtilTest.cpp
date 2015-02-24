#include "../src/Util.hpp"
#include <QString>
#include <QtTest>

class UtilTest : public QObject {
	Q_OBJECT
	public:
		UtilTest();

	private Q_SLOTS:
		void initTestCase();
		void cleanupTestCase();
		void testFindDuplicates();
};

UtilTest::UtilTest()
{
}

void UtilTest::initTestCase()
{
}

void UtilTest::cleanupTestCase()
{
}

void UtilTest::testFindDuplicates()
{
	QStringList list = { "a", "b", "b", "c" };
	QStringList duplicates = findDuplicates( list );
	QStringList expected = { "b" };

	QCOMPARE( duplicates, expected );
}

QTEST_APPLESS_MAIN(UtilTest)

#include "UtilTest.moc"
