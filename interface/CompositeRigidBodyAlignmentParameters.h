
#ifndef Alignment_CommonAlignmentParametrization_CompositeRigidBodyAlignmentParameters_h
#define Alignment_CommonAlignmentParametrization_CompositeRigidBodyAlignmentParameters_h

#include <vector>

#include "Geometry/CommonDetAlgo/interface/AlgebraicObjects.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Alignment/CommonAlignment/interface/Alignable.h"

#include "Alignment/CommonAlignmentParametrization/interface/RigidBodyAlignmentParameters.h"

/// Alignment parameters for 'higher level' object.
///  Derived from RigidBodyAlignmentParameters so that
///  derivatives method can be redefined
///

class CompositeRigidBodyAlignmentParameters : public RigidBodyAlignmentParameters 
{

public:

  /// Constructor
  CompositeRigidBodyAlignmentParameters(Alignable* object, 
										const AlgebraicVector& par, 
										const AlgebraicSymMatrix& cov);

  /// Constructor with selection
  CompositeRigidBodyAlignmentParameters(Alignable* object, 
										const AlgebraicVector& par, 
										const AlgebraicSymMatrix& cov, 
										const std::vector<bool>& sel);

  /// Clone method
  RigidBodyAlignmentParameters* clone( const AlgebraicVector& par, 
									   const AlgebraicSymMatrix& cov) const;
 
  /// Clone method with selection
  RigidBodyAlignmentParameters* cloneFromSelected( const AlgebraicVector& par, 
												   const AlgebraicSymMatrix& cov ) const;

  /// get derivatives
  AlgebraicMatrix derivatives( const TrajectoryStateOnSurface tsos, 
							   AlignableDet* alidet ) const;

};

#endif

