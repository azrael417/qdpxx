#include "unittest.h"
#include "timeVaxpyDouble.h"

using namespace std;

static double N_SECS=10;

// AXPY kernel (vaxpy4): y = ax + y (or y += ax)
void
time_VAXPY::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  Double a = Double(2.3);
  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64 ar = a.elem().elem().elem().elem();
  REAL64* aptr = &ar;
  int n_4vec = (all.end() - all.start() + 1);
  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl <<  "\t Timing VAXPY4 Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
       vaxpy4(yptr, aptr, xptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
       vaxpy4(yptr, aptr, xptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VAXPY4 Kernel: " << perf << " Mflops" << endl;

}

// AXPYZ kernel (vaxpyz4): z = ax + y
void
time_VAXPYZ::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  LatticeDiracFermionD3 z;
  Double a = Double(2.3);
  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64* zptr = &(z.elem(all.start()).elem(0).elem(0).real());
  REAL64 ar = a.elem().elem().elem().elem();
  REAL64* aptr = &ar;
  int n_4vec = (all.end() - all.start() + 1);
  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "\t Timing VAXPYZ4 Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
       vaxpyz4(zptr, aptr, xptr, yptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
       vaxpyz4(zptr, aptr, xptr, yptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VAXPYZ4 Kernrel: " << perf << " Mflops" << endl;

}


// VAXMYZ kernel z aliases y (vaxmyz4): y = ax - y 
void
time_VAXMY::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  Double a = Double(2.3);
  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64 ar = a.elem().elem().elem().elem();
  REAL64* aptr = &ar;
  int n_4vec = (all.end() - all.start() + 1);
  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "\t Timing VAXMYZ4 (aliased) Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      vaxmyz4(yptr, aptr, xptr, yptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    vaxmyz4(yptr, aptr, xptr, yptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VAXMYZ4 Kernel (aliased): " << perf << " Mflops" << endl;

}


// VAXMYZ kernel. (vaxmyz4): z=ax - y
void
time_VAXMYZ::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  LatticeDiracFermionD3 z;
  Double a = Double(2.3);
  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64* zptr = (REAL64 *)&(z.elem(all.start()).elem(0).elem(0).real());
  REAL64 ar = a.elem().elem().elem().elem();
  REAL64* aptr = &ar;
  int n_4vec = (all.end() - all.start() + 1);
  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "Timing VAXMYZ4 Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      vaxmyz4(zptr, aptr, xptr, yptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    vaxmyz4(zptr, aptr, xptr,yptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VAXMYZ4 Kernel: " << perf << " Mflops" << endl;

}

// VAXPBYZ kernel: (vaxpbyz4) z = ax + by
void
time_VAXPBYZ::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  LatticeDiracFermionD3 z;
  Double a = Double(2.3);
  Double b = Double(0.5);

  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64* zptr = (REAL64 *)&(z.elem(all.start()).elem(0).elem(0).real());
  REAL64 ar = a.elem().elem().elem().elem();
  REAL64* aptr = &ar;

  REAL64 br = b.elem().elem().elem().elem();
  REAL64* bptr = &ar;

  int n_4vec = (all.end() - all.start() + 1);
  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "Timing VAXPBYZ4 Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      vaxpbyz4(zptr, aptr, xptr, bptr, yptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
      vaxpbyz4(zptr, aptr, xptr, bptr, yptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(6*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VAXPBYZ4 Kernel: " << perf << " Mflops" << endl;

}

// VAXPBY kernel (z aliases y): y = ax + by 
void
time_VAXPBY::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  LatticeDiracFermionD3 z;
  Double a = Double(2.3);
  Double b = Double(0.5);

  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64 ar = a.elem().elem().elem().elem();
  REAL64* aptr = &ar;

  REAL64 br = b.elem().elem().elem().elem();
  REAL64* bptr = &ar;

  int n_4vec = (all.end() - all.start() + 1);
  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "Timing VAXPBY4 (aliased) Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      vaxpbyz4(yptr, aptr, xptr, bptr, yptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    vaxpbyz4(yptr, aptr, xptr, bptr, yptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(6*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VAXPBY4 (aliased) Kernel: " << perf << " Mflops" << endl;

}

// VSCAL Kernel: y = a*x
void
time_VSCAL::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  LatticeDiracFermionD3 z;
  Double a = Double(2.3);

  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64 ar = a.elem().elem().elem().elem();
  REAL64* aptr = &ar;

  int n_4vec = (all.end() - all.start() + 1);
  gaussian(x);

  QDPIO::cout << endl << "Timing VSCAL4 Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      vscal4(yptr, aptr, xptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
      vscal4(yptr, aptr, xptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(2*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VSCAL4 Kernel: " << perf << " Mflops" << endl;

}


//


void
time_LOCAL_SUMSQ::run(void) 
{

  LatticeDiracFermionD3 x;
  Double lnorm;

  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* res = &(lnorm.elem().elem().elem().elem());
  int n_4vec = (all.end() - all.start() + 1);

  gaussian(x);

  QDPIO::cout << endl << "Timing LOCAL SUMSQ Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      local_sumsq4(res,xptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
      local_sumsq4(res, xptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::sitesOnNode());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "Local SUMSQ Kernel: " << perf << " Mflops" << endl;

}


void
time_SUMSQ::run(void) 
{

  LatticeDiracFermionD3 x;
  Double lnorm;

  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* res = &(lnorm.elem().elem().elem().elem());
  int n_4vec = (all.end() - all.start() + 1);

  gaussian(x);

  QDPIO::cout << endl << "SUMSQ Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      local_sumsq4(res, xptr, n_4vec);
      Internal::globalSum(lnorm);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
      local_sumsq4(res, xptr, n_4vec);
      Internal::globalSum(lnorm);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "SUMSQ Kernel: " << perf << " Mflops" << endl;

}




void
time_LOCAL_VCDOT::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  DComplex lnorm;


  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64* res = &(lnorm.elem().elem().elem().real());
  int n_4vec = (all.end() - all.start() + 1);

  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "Timing LOCAL VCDOT Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      local_vcdot4(res, yptr, xptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    local_vcdot4(res, yptr, xptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(8*Nc*Ns*Layout::sitesOnNode());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "Local VCDOT Kernel: " << perf << " Mflops" << endl;

}


void
time_VCDOT::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  DComplex lnorm;

  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64* res = &(lnorm.elem().elem().elem().real());
  int n_4vec = (all.end() - all.start() + 1);

  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "VCDOT Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      local_vcdot4(res, yptr, xptr, n_4vec);
      Internal::globalSum(lnorm);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    local_vcdot4(res, yptr, xptr, n_4vec);
    Internal::globalSum(lnorm);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(8*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VCDOT Kernel: " << perf << " Mflops" << endl;
}

void
time_LOCAL_VCDOT_REAL::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  Double lnorm;


  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64* res = &(lnorm.elem().elem().elem().elem());
  int n_4vec = (all.end() - all.start() + 1);

  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "Timing LOCAL VCDOT REAL Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      local_vcdot_real4(res, yptr, xptr, n_4vec);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    local_vcdot_real4(res, yptr, xptr, n_4vec);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::sitesOnNode());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "Local VCDOT REAL Kernel: " << perf << " Mflops" << endl;

}


void
time_VCDOT_REAL::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  Double lnorm;

  REAL64* xptr = (REAL64 *)&(x.elem(all.start()).elem(0).elem(0).real());
  REAL64* yptr = (REAL64 *)&(y.elem(all.start()).elem(0).elem(0).real());
  REAL64* res = &(lnorm.elem().elem().elem().elem());
  int n_4vec = (all.end() - all.start() + 1);

  gaussian(x);
  gaussian(y);

  QDPIO::cout << endl << "VCDOT REAL Kernel " <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    
    for(int i=0; i < iters; i++) { 
      local_vcdot_real4(res, yptr, xptr, n_4vec);
      Internal::globalSum(lnorm);
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    local_vcdot_real4(res, yptr, xptr, n_4vec);
    Internal::globalSum(lnorm);
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "VCDOT REAL Kernel: " << perf << " Mflops" << endl;
}



















#if 0
void
time_QDP_PEQ::run(void) 
{

  LatticeFermionD3 x;
  LatticeFermionD3 y;
  Double a = Double(2.3);

  gaussian(x);
  gaussian(y);

  QDPIO::cout << "Timing QDP++ += operation" <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << endl << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    for(int i=0; i < iters; i++) { 
      y[all] += a*x;
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    y[all] += a*x;
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "Operator +=: " << perf << " Mflops" << endl;

}


void time_QDP_AXPYZ::run(void) 
{

  LatticeDiracFermionD3 x;
  LatticeDiracFermionD3 y;
  LatticeDiracFermionD3 z;
  Double a = Double(2.3);

  gaussian(x);
  gaussian(y);

  QDPIO::cout << "Timing QDP++ AXPYZ operation  "  <<endl;

  StopWatch swatch;
  double n_secs = N_SECS;
  int iters=1;
  double time=0;
  QDPIO::cout << endl << "\t Calibrating for " << n_secs << " seconds " << endl;
  do {
    swatch.reset();
    swatch.start();
    for(int i=0; i < iters; i++) { 
      z[all]= a*x + y;
    }
    swatch.stop();
    time=swatch.getTimeInSeconds();

    // Average time over nodes
    Internal::globalSum(time);
    time /= (double)Layout::numNodes();

    if (time < n_secs) {
      iters *=2;
      QDPIO::cout << "." << flush;
    }
  }
  while ( time < (double)n_secs );
      
  QDPIO::cout << endl;
  QDPIO::cout << "\t Timing with " << iters << " counts" << endl;

  swatch.reset();
  swatch.start();
  
  for(int i=0; i < iters; ++i) {
    z[all]=a*x+y;
  }
  swatch.stop();
  time=swatch.getTimeInSeconds();

  // Average time over nodes
  Internal::globalSum(time);
  time /= (double)Layout::numNodes();
  time /= (double)iters;

  double flops=(double)(4*Nc*Ns*Layout::vol());
  double perf=(flops/time)/(double)(1024*1024);
  QDPIO::cout << "Triad z=ax + y: " << perf << " Mflops" << endl;

}
#endif
