#ifndef QDP_GENERIC_FUSED_SPIN_PROJ_EVALUATES_H
#define QDP_GENERIC_FUSED_SPIN_PROJ_EVALUATES_H


/* Evaluates for things like adj(u)*spinProjectDir0Plus(y) */
using namespace QDP;
QDP_BEGIN_NAMESPACE(QDP);

typedef PScalar< PColorMatrix< RComplex<REAL>, 3> > SU3Mat;


// HalfVec = adj(u)*SpinProjectDir0Plus(Vec);
template<>
inline
void evaluate(OLattice< HVec >& d,
              const OpAssign& op,
              const QDPExpr<
	              BinaryNode< 
	                FnAdjMultSprojDir0Plus,
	               
	                UnaryNode< OpIdentity, 
	                  Reference< QDPType< SU3Mat, OLattice< SU3Mat > > > >,
	               
	                  UnaryNode< OpIdentity,
                          Reference< QDPType< FVec,   OLattice< FVec > > > >
                      >,
	              OLattice< HVec > 
                    >&rhs,
	      const Subset& s)
{
  const OLattice< SU3Mat >& u = static_cast< const OLattice< SU3Mat >& >(rhs.expression().left().child());
  const OLattice< FVec >& a = static_cast< const OLattice< FVec >& >(rhs.expression().right().child());


  const int *tab = s.siteTable().slice();
  for(int j=0; j < s.numSiteTable(); j++) { 
    int site = tab[j];

    HVec tmp;
    inlineSpinProjDir0Plus( (REAL *)&(a.elem(site).elem(0).elem(0).real()),
			    (REAL *)&(tmp.elem(0).elem(0).real()),
			    1);


    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(0), d.elem(site).elem(0));
    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(1), d.elem(site).elem(1));   
 
  }

}

// HalfVec = adj(u)*SpinProjectDir0Minus(Vec);
template<>
inline
void evaluate(OLattice< HVec >& d,
              const OpAssign& op,
              const QDPExpr<
	              BinaryNode< 
	                FnAdjMultSprojDir0Minus,
	               
	                UnaryNode< OpIdentity, 
	                  Reference< QDPType< SU3Mat, OLattice< SU3Mat > > > >,
	               
	                  UnaryNode< OpIdentity,
                          Reference< QDPType< FVec,   OLattice< FVec > > > >
                      >,
	              OLattice< HVec > 
                    >&rhs,
	      const Subset& s)
{
  const OLattice< SU3Mat >& u = static_cast< const OLattice< SU3Mat >& >(rhs.expression().left().child());
  const OLattice< FVec >& a = static_cast< const OLattice< FVec >& >(rhs.expression().right().child());


  const int *tab = s.siteTable().slice();
  for(int j=0; j < s.numSiteTable(); j++) { 
    int site = tab[j];


    HVec tmp;
    inlineSpinProjDir0Minus( (REAL *)&(a.elem(site).elem(0).elem(0).real()),
			    (REAL *)&(tmp.elem(0).elem(0).real()),
			    1);


    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(0), d.elem(site).elem(0));
    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(1), d.elem(site).elem(1));   
 
  }

}

// HalfVec = adj(u)*SpinProjectDir1Plus(Vec);
template<>
inline
void evaluate(OLattice< HVec >& d,
              const OpAssign& op,
              const QDPExpr<
	              BinaryNode< 
	                FnAdjMultSprojDir1Plus,
	               
	                UnaryNode< OpIdentity, 
	                  Reference< QDPType< SU3Mat, OLattice< SU3Mat > > > >,
	               
	                  UnaryNode< OpIdentity,
                          Reference< QDPType< FVec,   OLattice< FVec > > > >
                      >,
	              OLattice< HVec > 
                    >&rhs,
	      const Subset& s)
{
  const OLattice< SU3Mat >& u = static_cast< const OLattice< SU3Mat >& >(rhs.expression().left().child());
  const OLattice< FVec >& a = static_cast< const OLattice< FVec >& >(rhs.expression().right().child());


  const int *tab = s.siteTable().slice();
  for(int j=0; j < s.numSiteTable(); j++) { 
    int site = tab[j];


    HVec tmp;
    inlineSpinProjDir1Plus( (REAL *)&(a.elem(site).elem(0).elem(0).real()),
			    (REAL *)&(tmp.elem(0).elem(0).real()),
			    1);


    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(0), d.elem(site).elem(0));
    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(1), d.elem(site).elem(1));   
 
  }

}

// HalfVec = adj(u)*SpinProjectDir1Minus(Vec);
template<>
inline
void evaluate(OLattice< HVec >& d,
              const OpAssign& op,
              const QDPExpr<
	              BinaryNode< 
	                FnAdjMultSprojDir1Minus,
	               
	                UnaryNode< OpIdentity, 
	                  Reference< QDPType< SU3Mat, OLattice< SU3Mat > > > >,
	               
	                  UnaryNode< OpIdentity,
                          Reference< QDPType< FVec,   OLattice< FVec > > > >
                      >,
	              OLattice< HVec > 
                    >&rhs,
	      const Subset& s)
{
  const OLattice< SU3Mat >& u = static_cast< const OLattice< SU3Mat >& >(rhs.expression().left().child());
  const OLattice< FVec >& a = static_cast< const OLattice< FVec >& >(rhs.expression().right().child());

  const int *tab = s.siteTable().slice();
  for(int j=0; j < s.numSiteTable(); j++) { 
    int site = tab[j];

    HVec tmp;
    inlineSpinProjDir1Minus( (REAL *)&(a.elem(site).elem(0).elem(0).real()),
			    (REAL *)&(tmp.elem(0).elem(0).real()),
			    1);


    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(0), d.elem(site).elem(0));
    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(1), d.elem(site).elem(1));   
 
  }

}


// HalfVec = adj(u)*SpinProjectDir2Plus(Vec);
template<>
inline
void evaluate(OLattice< HVec >& d,
              const OpAssign& op,
              const QDPExpr<
	              BinaryNode< 
	                FnAdjMultSprojDir2Plus,
	               
	                UnaryNode< OpIdentity, 
	                  Reference< QDPType< SU3Mat, OLattice< SU3Mat > > > >,
	               
	                  UnaryNode< OpIdentity,
                          Reference< QDPType< FVec,   OLattice< FVec > > > >
                      >,
	              OLattice< HVec > 
                    >&rhs,
	      const Subset& s)
{
  const OLattice< SU3Mat >& u = static_cast< const OLattice< SU3Mat >& >(rhs.expression().left().child());
  const OLattice< FVec >& a = static_cast< const OLattice< FVec >& >(rhs.expression().right().child());


  const int *tab = s.siteTable().slice();
  for(int j=0; j < s.numSiteTable(); j++) { 
    int site = tab[j];

    HVec tmp;
    inlineSpinProjDir2Plus( (REAL *)&(a.elem(site).elem(0).elem(0).real()),
			    (REAL *)&(tmp.elem(0).elem(0).real()),
			    1);


    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(0), d.elem(site).elem(0));
    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(1), d.elem(site).elem(1));   
 
  }

}

// HalfVec = adj(u)*SpinProjectDir2Minus(Vec);
template<>
inline
void evaluate(OLattice< HVec >& d,
              const OpAssign& op,
              const QDPExpr<
	              BinaryNode< 
	                FnAdjMultSprojDir2Minus,
	               
	                UnaryNode< OpIdentity, 
	                  Reference< QDPType< SU3Mat, OLattice< SU3Mat > > > >,
	               
	                  UnaryNode< OpIdentity,
                          Reference< QDPType< FVec,   OLattice< FVec > > > >
                      >,
	              OLattice< HVec > 
                    >&rhs,
	      const Subset& s)
{
  const OLattice< SU3Mat >& u = static_cast< const OLattice< SU3Mat >& >(rhs.expression().left().child());
  const OLattice< FVec >& a = static_cast< const OLattice< FVec >& >(rhs.expression().right().child());


  const int *tab = s.siteTable().slice();
  for(int j=0; j < s.numSiteTable(); j++) { 
    int site = tab[j];


    HVec tmp;
    inlineSpinProjDir2Minus( (REAL *)&(a.elem(site).elem(0).elem(0).real()),
			    (REAL *)&(tmp.elem(0).elem(0).real()),
			    1);


    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(0), d.elem(site).elem(0));
    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(1), d.elem(site).elem(1));   
 
  }

}
// HalfVec = adj(u)*SpinProjectDir3Plus(Vec);
template<>
inline
void evaluate(OLattice< HVec >& d,
              const OpAssign& op,
              const QDPExpr<
	              BinaryNode< 
	                FnAdjMultSprojDir3Plus,
	               
	                UnaryNode< OpIdentity, 
	                  Reference< QDPType< SU3Mat, OLattice< SU3Mat > > > >,
	               
	                  UnaryNode< OpIdentity,
                          Reference< QDPType< FVec,   OLattice< FVec > > > >
                      >,
	              OLattice< HVec > 
                    >&rhs,
	      const Subset& s)
{
  const OLattice< SU3Mat >& u = static_cast< const OLattice< SU3Mat >& >(rhs.expression().left().child());
  const OLattice< FVec >& a = static_cast< const OLattice< FVec >& >(rhs.expression().right().child());

  REAL *aptr =(REAL *)&(a.elem(s.start()).elem(0).elem(0).real());


  const int *tab = s.siteTable().slice();
  for(int j=0; j < s.numSiteTable(); j++) { 
    int site = tab[j];

    HVec tmp;
    inlineSpinProjDir3Plus( (REAL *)&(a.elem(site).elem(0).elem(0).real()),
			    (REAL *)&(tmp.elem(0).elem(0).real()),
			    1);


    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(0), d.elem(site).elem(0));
    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(1), d.elem(site).elem(1));   
 
  }

}

// HalfVec = adj(u)*SpinProjectDir3Minus(Vec);
template<>
inline
void evaluate(OLattice< HVec >& d,
              const OpAssign& op,
              const QDPExpr<
	              BinaryNode< 
	                FnAdjMultSprojDir3Minus,
	               
	                UnaryNode< OpIdentity, 
	                  Reference< QDPType< SU3Mat, OLattice< SU3Mat > > > >,
	               
	                  UnaryNode< OpIdentity,
                          Reference< QDPType< FVec,   OLattice< FVec > > > >
                      >,
	              OLattice< HVec > 
                    >&rhs,
	      const Subset& s)
{
  const OLattice< SU3Mat >& u = static_cast< const OLattice< SU3Mat >& >(rhs.expression().left().child());
  const OLattice< FVec >& a = static_cast< const OLattice< FVec >& >(rhs.expression().right().child());

  const int *tab = s.siteTable().slice();
  for(int j=0; j < s.numSiteTable(); j++) { 
    int site = tab[j];

    HVec tmp;
    inlineSpinProjDir3Minus( (REAL *)&(a.elem(site).elem(0).elem(0).real()),
			    (REAL *)&(tmp.elem(0).elem(0).real()),
			    1);


    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(0), d.elem(site).elem(0));
    _inline_mult_adj_su3_mat_vec(u.elem(site).elem(), tmp.elem(1), d.elem(site).elem(1));   
 
  }

}

QDP_END_NAMESPACE();

#endif