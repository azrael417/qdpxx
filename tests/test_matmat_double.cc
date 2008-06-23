#include "qdp.h"
#include "unittest.h"
#include "testvol.h"


#include "testMatScalMultDouble.h"
#include "testMatPeqMatDouble.h"

using namespace QDP;

int main(int argc, char **argv)
{
  // Initialize UnitTest jig
  TestRunner  tests(&argc, &argv, nrow_in);
  QDPIO::cout << "Volume= { " << Layout::lattSize()[0]
	      << " , " << Layout::lattSize()[1]
	      << " , " << Layout::lattSize()[2]
	      << " , " << Layout::lattSize()[3] << " } " << endl;

  
  tests.addTest(new testScalMult1_1(), "testScalMult1_1" );
  tests.addTest(new testScalMult1_2(), "testScalMult1_2" );
  tests.addTest(new testScalMult1_3(), "testScalMult1_3" );

  tests.addTest(new testScalMult2_1(), "testScalMult2_1" );
  tests.addTest(new testScalMult2_2(), "testScalMult2_2" );
  tests.addTest(new testScalMult2_3(), "testScalMult2_3" );

  tests.addTest(new testMPeqM_1(), "testMPeqM_1" );
  tests.addTest(new testMPeqM_2(), "testMPeqM_2" );
  tests.addTest(new testMPeqM_3(), "testMPeqM_3" );

  tests.addTest(new testMMeqM_1(), "testMMeqM_1" );
  tests.addTest(new testMMeqM_2(), "testMMeqM_2" );
  tests.addTest(new testMMeqM_3(), "testMMeqM_3" );

  tests.addTest(new testMPeqH_1(), "testMPeqH_1" );
  tests.addTest(new testMPeqH_2(), "testMPeqH_2" );
  tests.addTest(new testMPeqH_3(), "testMPeqH_3" );

  tests.addTest(new testMMeqH_1(), "testMMeqH_1" );
  tests.addTest(new testMMeqH_2(), "testMMeqH_2" );
  tests.addTest(new testMMeqH_3(), "testMMeqH_3" );

  // Run all tests
  tests.run();

  // Testjig is destroyed
  tests.summary();
}
