#include <string.h>
#include <vector>
#include <maya/MIOStream.h>
#include <math.h>

#include <maya/MPxDeformerNode.h> 
#include <maya/MItGeometry.h>
#include <maya/MPxLocatorNode.h> 

#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnMatrixAttribute.h>

#include <maya/MFnPlugin.h>
#include <maya/MFnDependencyNode.h>

#include <maya/MFnNurbsSurface.h>
#include <maya/MFnNurbsCurve.h>
#include <maya/MFnMesh.h>

#include <maya/MTypeId.h> 
#include <maya/MPlug.h>

#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MArrayDataHandle.h>

#include <maya/MPoint.h>
#include <maya/MVector.h>
#include <maya/MQuaternion.h>
#include <maya/MMatrix.h>

#include <maya/MGlobal.h>

#ifdef _MSC_VER
  #define MAYA_EXPORT extern "C" __declspec(dllexport) MStatus _cdecl
#else
  #define MAYA_EXPORT extern "C" MStatus
#endif

class HM_WrapDeformer : public MPxDeformerNode
{
public:
  HM_WrapDeformer();
  virtual ~HM_WrapDeformer();

  static void* creator();
  static MStatus initialize();

  // deformation function
  //
  virtual MStatus deform(MDataBlock& block, MItGeometry& iter, const MMatrix& mat, unsigned int multiIndex);

public:

  // local node attributes
  static MObject targetSurface;
  static MObject worldReference;
  static MObject uMin;
  static MObject vMin;
  static MObject uMax;
  static MObject vMax;
  static MObject uOffset;
  static MObject vOffset;
  static MObject zOffset;
  static MObject uScale;
  static MObject vScale;
  static MObject zScale;
  static MObject uvRotation;
  static MTypeId id;

private:
};

MTypeId HM_WrapDeformer::id( 0x0011AF3F );

// local attributes
//
MObject HM_WrapDeformer::targetSurface;
MObject HM_WrapDeformer::worldReference;
MObject HM_WrapDeformer::uMin;
MObject HM_WrapDeformer::vMin;
MObject HM_WrapDeformer::uMax;
MObject HM_WrapDeformer::vMax;
MObject HM_WrapDeformer::uOffset;
MObject HM_WrapDeformer::vOffset;
MObject HM_WrapDeformer::zOffset;
MObject HM_WrapDeformer::uScale;
MObject HM_WrapDeformer::vScale;
MObject HM_WrapDeformer::zScale;
MObject HM_WrapDeformer::uvRotation;

HM_WrapDeformer::HM_WrapDeformer() {}
HM_WrapDeformer::~HM_WrapDeformer() {}

void* HM_WrapDeformer::creator()
{
  return new HM_WrapDeformer();
}

MStatus HM_WrapDeformer::initialize()
{
  // local attribute initialization

  MFnNumericAttribute nAttr;
  MFnTypedAttribute tAttr;
  MFnMatrixAttribute mAttr;

  targetSurface = tAttr.create("targetSurface", "targetSurface", MFnData::kNurbsSurface);
  tAttr.setStorable(true);
  tAttr.setConnectable(true);
  tAttr.setWritable(true);
  tAttr.setReadable(true);

  worldReference = mAttr.create("worldReference", "worldReference", MFnMatrixAttribute::kDouble);
  mAttr.setStorable(true);
  mAttr.setConnectable(true);
  mAttr.setWritable(true);
  mAttr.setReadable(true);

  uMin = nAttr.create("uMin", "uMin",  MFnNumericData::kDouble, -1.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  vMin = nAttr.create("vMin", "vMin",  MFnNumericData::kDouble, -1.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  uMax = nAttr.create("uMax", "uMax",  MFnNumericData::kDouble, 1.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  vMax = nAttr.create("vMax", "vMax",  MFnNumericData::kDouble, 1.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  uOffset = nAttr.create("uOffset", "uOffset",  MFnNumericData::kDouble, 0.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  vOffset = nAttr.create("vOffset", "vOffset",  MFnNumericData::kDouble, 0.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  zOffset = nAttr.create("zOffset", "zOffset",  MFnNumericData::kDouble, 0.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  uScale = nAttr.create("uScale", "uScale",  MFnNumericData::kDouble, 1.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  vScale = nAttr.create("vScale", "vScale",  MFnNumericData::kDouble, 1.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  zScale = nAttr.create("zScale", "zScale",  MFnNumericData::kDouble, 1.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);
  uvRotation = nAttr.create("uvRotation", "uvRotation",  MFnNumericData::kDouble, 0.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);

  addAttribute(targetSurface);
  addAttribute(worldReference);
  addAttribute(uMin);
  addAttribute(vMin);
  addAttribute(uMax);
  addAttribute(vMax);
  addAttribute(uOffset);
  addAttribute(vOffset);
  addAttribute(zOffset);
  addAttribute(uScale);
  addAttribute(vScale);
  addAttribute(zScale);
  addAttribute(uvRotation);

  attributeAffects(HM_WrapDeformer::targetSurface, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::worldReference, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::uMin, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::vMin, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::uMax, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::vMax, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::uOffset, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::vOffset, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::zOffset, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::uScale, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::vScale, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::zScale, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_WrapDeformer::uvRotation, HM_WrapDeformer::outputGeom);

  return MStatus::kSuccess;
}


MStatus
HM_WrapDeformer::deform( MDataBlock& block,
                                MItGeometry& iter,
                                const MMatrix& /*m*/,
                                unsigned int multiIndex)
//
// Method: deform
//
// Description:   Deform the point with a squash algorithm
//
// Arguments:
//   block              : the datablock of the node
//       iter           : an iterator for the geometry to be deformed
//   m                  : matrix to transform the point into world space
//       multiIndex : the index of the geometry that we are deforming
//
//
{
  MStatus returnStatus;
  
  // Envelope data from the base class.
  // The envelope is simply a scale factor.
  //
  MDataHandle envData = block.inputValue(envelope, &returnStatus);
  if (MS::kSuccess != returnStatus) return returnStatus;
  float env = envData.asFloat();  

  MDataHandle targetSurfaceHandle = block.inputValue(targetSurface, &returnStatus);
  if (MS::kSuccess != returnStatus) return returnStatus;

  MObject targetSurfaceObject = targetSurfaceHandle.asNurbsSurface();
  if(targetSurfaceObject.isNull())
    return MS::kInvalidParameter;

  MFnNurbsSurface targetSurfaceFn(targetSurfaceObject);

  MDataHandle worldReferenceHandle = block.inputValue(worldReference, &returnStatus);
  if (MS::kSuccess != returnStatus) return returnStatus;
  MMatrix worldReferenceInv = worldReferenceHandle.asMatrix().inverse();

  double uMinValue = block.inputValue(uMin).asDouble();
  double vMinValue = block.inputValue(vMin).asDouble();
  double uMaxValue = block.inputValue(uMax).asDouble();
  double vMaxValue = block.inputValue(vMax).asDouble();
  double uCenterValue = 0.5;
  double vCenterValue = 0.5;
  double uOffsetValue = block.inputValue(uOffset).asDouble();
  double vOffsetValue = block.inputValue(vOffset).asDouble();
  double zOffsetValue = block.inputValue(zOffset).asDouble();
  double uScaleValue = block.inputValue(uScale).asDouble();
  double vScaleValue = block.inputValue(vScale).asDouble();
  double zScaleValue = block.inputValue(zScale).asDouble();
  double uvRotationValue = block.inputValue(uvRotation).asDouble();

  unsigned int index = 0;
  for ( ; !iter.isDone(); iter.next(), index++) {

    MPoint oriPt = iter.position();
    MPoint pt = oriPt * worldReferenceInv;

    double u, v, z;
    u = (pt.x - uMinValue) / (uMaxValue - uMinValue);
    v = (pt.y - vMinValue) / (vMaxValue - vMinValue);
    z = pt.z;

    u = u - uCenterValue;
    v = v - vCenterValue;

    if(uvRotationValue != 0.0)
    {
      MVector uvPos(u, v, 0.0);
      MQuaternion q;
      q.setAxisAngle(MVector(0, 0, 1), uvRotationValue * 3.141592653589793 / 180.0);
      uvPos = uvPos.rotateBy(q);
      u = uvPos.x;
      v = uvPos.y;
    }

    u = uOffsetValue + u * uScaleValue;
    v = vOffsetValue + v * vScaleValue;
    u = u + uCenterValue;
    v = v + vCenterValue;

    if(targetSurfaceFn.getPointAtParam(u, v, pt) != MS::kSuccess)
      continue;
    pt += targetSurfaceFn.normal(u, v) * (z * zScaleValue + zOffsetValue);

    pt = oriPt * (1.0 - env) + pt * env;
    iter.setPosition(pt);
  }
  return returnStatus;
}

class HM_CopyPointsDeformer : public MPxDeformerNode
{
public:
  HM_CopyPointsDeformer();
  virtual ~HM_CopyPointsDeformer();

  static void* creator();
  static MStatus initialize();

  // deformation function
  //
  virtual MStatus deform(MDataBlock& block, MItGeometry& iter, const MMatrix& mat, unsigned int multiIndex);

public:

  // local node attributes
  static MObject targetMesh;
  static MTypeId id;

private:
};

MTypeId HM_CopyPointsDeformer::id( 0x0011AF3E );

// local attributes
//
MObject HM_CopyPointsDeformer::targetMesh;

HM_CopyPointsDeformer::HM_CopyPointsDeformer() {}
HM_CopyPointsDeformer::~HM_CopyPointsDeformer() {}

void* HM_CopyPointsDeformer::creator()
{
  return new HM_CopyPointsDeformer();
}

MStatus HM_CopyPointsDeformer::initialize()
{
  // local attribute initialization

  MFnTypedAttribute tAttr;

  targetMesh = tAttr.create("targetMesh", "targetMesh", MFnData::kMesh);
  tAttr.setStorable(true);
  tAttr.setConnectable(true);
  tAttr.setWritable(true);
  tAttr.setReadable(true);

  addAttribute(targetMesh);

  attributeAffects(HM_CopyPointsDeformer::targetMesh, HM_WrapDeformer::outputGeom);

  return MStatus::kSuccess;
}


MStatus
HM_CopyPointsDeformer::deform( MDataBlock& block,
                                MItGeometry& iter,
                                const MMatrix& /*m*/,
                                unsigned int multiIndex)
//
// Method: deform
//
// Description:   Deform the point with a squash algorithm
//
// Arguments:
//   block              : the datablock of the node
//       iter           : an iterator for the geometry to be deformed
//   m                  : matrix to transform the point into world space
//       multiIndex : the index of the geometry that we are deforming
//
//
{
  MStatus returnStatus;
  
  // Envelope data from the base class.
  // The envelope is simply a scale factor.
  //
  MDataHandle envData = block.inputValue(envelope, &returnStatus);
  if (MS::kSuccess != returnStatus) return returnStatus;
  float env = envData.asFloat();  

  MDataHandle targetMeshHandle = block.inputValue(targetMesh, &returnStatus);
  if (MS::kSuccess != returnStatus) return returnStatus;

  MObject targetMeshObject = targetMeshHandle.asMesh();
  if(targetMeshObject.isNull())
    return MS::kInvalidParameter;

  MFnMesh targetMeshFn(targetMeshObject);

  int index = 0;
  for ( ; !iter.isDone(); iter.next(), index++) {

    MPoint pt;
    if(targetMeshFn.getPoint(index, pt) != MS::kSuccess)
      break;

    MPoint oriPt = iter.position();
    pt = oriPt * (1.0 - env) + pt * env;
    iter.setPosition(pt);
  }
  return returnStatus;
}

class HM_PushCurveDeformer : public MPxDeformerNode
{
public:
  HM_PushCurveDeformer();
  virtual ~HM_PushCurveDeformer();

  static void* creator();
  static MStatus initialize();

  // deformation function
  //
  virtual MStatus deform(MDataBlock& block, MItGeometry& iter, const MMatrix& mat, unsigned int multiIndex);

public:

  // local node attributes
  static MObject factor;
  static MObject axis;
  static MTypeId id;

private:
};

MTypeId HM_PushCurveDeformer::id( 0x0011AF3D );

// local attributes
//
MObject HM_PushCurveDeformer::factor;
MObject HM_PushCurveDeformer::axis;

HM_PushCurveDeformer::HM_PushCurveDeformer() {}
HM_PushCurveDeformer::~HM_PushCurveDeformer() {}

void* HM_PushCurveDeformer::creator()
{
  return new HM_PushCurveDeformer();
}

MStatus HM_PushCurveDeformer::initialize()
{
  // local attribute initialization

  MFnNumericAttribute nAttr;
  MFnTypedAttribute tAttr;

  factor = nAttr.create("factor", "factor",  MFnNumericData::kDouble, 1.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);

  axis = nAttr.create("axis", "axis",  MFnNumericData::k3Double, 0.0);
  nAttr.setStorable(true);
  nAttr.setConnectable(true);
  nAttr.setWritable(true);
  nAttr.setReadable(true);

  addAttribute(factor);
  addAttribute(axis);

  attributeAffects(HM_PushCurveDeformer::factor, HM_WrapDeformer::outputGeom);
  attributeAffects(HM_PushCurveDeformer::axis, HM_WrapDeformer::outputGeom);

  return MStatus::kSuccess;
}


MStatus
HM_PushCurveDeformer::deform( MDataBlock& block,
                                MItGeometry& iter,
                                const MMatrix& /*m*/,
                                unsigned int multiIndex)
//
// Method: deform
//
// Description:   Deform the point with a squash algorithm
//
// Arguments:
//   block              : the datablock of the node
//       iter           : an iterator for the geometry to be deformed
//   m                  : matrix to transform the point into world space
//       multiIndex : the index of the geometry that we are deforming
//
//
{
  MStatus returnStatus;
  
  // Envelope data from the base class.
  // The envelope is simply a scale factor.
  //
  MDataHandle envData = block.inputValue(envelope, &returnStatus);
  if (MS::kSuccess != returnStatus) return returnStatus;
  float env = envData.asFloat();  

  MArrayDataHandle sourceCurveArrayHandle = block.outputArrayValue(input, &returnStatus);
  if (MS::kSuccess != returnStatus) return returnStatus;

  returnStatus = sourceCurveArrayHandle.jumpToElement( multiIndex );
  if (MS::kSuccess != returnStatus) return returnStatus;

  MObject sourceCurveObject = sourceCurveArrayHandle.outputValue().child( inputGeom ).asNurbsCurve();
  if(sourceCurveObject.isNull())
    return MS::kInvalidParameter;

  MFnNurbsCurve sourceCurveFn(sourceCurveObject);

  double factorValue = block.inputValue(factor).asDouble();
  MVector axisValue = block.inputValue(axis).asVector().normal();
  if(axisValue.x == 0.0 && axisValue.y == 0.0 && axisValue.z == 0.0)
  {
    MGlobal::displayError("You need to set the axis for the HM_PushCurveDeformer.");
    return MS::kInvalidParameter;
  }

  // MVectorArray tangents(iter.count());
  // for(int i=0;i<tangents.length();i++)
  // {
    // tangents[i] = sourceCurveFn.tangent((double)i);
  // }

  int index = 0;
  for ( ; !iter.isDone(); iter.next(), index++) {

    MPoint oriPt = iter.position();

    MPoint pt = oriPt;
    double param = double(iter.count() - 2 - sourceCurveFn.degree()) * double(index) / double(iter.count()-1);
    // sourceCurveFn.closestPoint(pt, &param);
    MVector tangent = sourceCurveFn.tangent(param).normal();
    // MVector tangent = tangents[index];
    MVector direction = tangent ^ axisValue;
    pt += direction * factorValue;

    pt = oriPt * (1.0 - env) + pt * env;
    iter.setPosition(pt);
  }
  return returnStatus;
}

// standard initialization procedures
//

#if defined(OSMac_)
__attribute__ ((visibility("default")))
#endif
MAYA_EXPORT initializePlugin( MObject obj )
{
  MStatus result;
  MFnPlugin plugin( obj, PLUGIN_COMPANY, "3.0", "Any");
  result = plugin.registerNode( "HM_WrapDeformer", HM_WrapDeformer::id, HM_WrapDeformer::creator, 
                                                   HM_WrapDeformer::initialize, MPxNode::kDeformerNode );
  result = plugin.registerNode( "HM_CopyPointsDeformer", HM_CopyPointsDeformer::id, HM_CopyPointsDeformer::creator, 
                                                   HM_CopyPointsDeformer::initialize, MPxNode::kDeformerNode );
  result = plugin.registerNode( "HM_PushCurveDeformer", HM_PushCurveDeformer::id, HM_PushCurveDeformer::creator, 
                                                   HM_PushCurveDeformer::initialize, MPxNode::kDeformerNode );

  return result;
}

#if defined(OSMac_)
__attribute__ ((visibility("default")))
#endif
MAYA_EXPORT uninitializePlugin( MObject obj)
{
  MStatus result;
  MFnPlugin plugin( obj );
  result = plugin.deregisterNode( HM_WrapDeformer::id );
  result = plugin.deregisterNode( HM_CopyPointsDeformer::id );
  result = plugin.deregisterNode( HM_PushCurveDeformer::id );
  return result;
}
