
#include <iostream>
#include "Eulerfluid1.h"
using namespace PHYSZY;


Eulerfluid1 game;


void Eulerfluid1::saveAsLiquidXml(/*const Engine::ScalarGrid3Ptr & sdf, */const std::string & rootDir, int frameCnt)
{
    // Triangulate and save to .obj.
    /*TriangleMesh3 mesh;
    int flag = kDirectionAll & ~kDirectionDown;
    marchingCubes(sdf->constDataAccessor(), sdf->gridSpacing(), sdf->dataOrigin(), &mesh, 0.0, flag);
    char basename[256];
    snprintf(basename, sizeof(basename), "frame_%06d.obj", frameCnt);
    std::string objName(basename);
    std::string filename = rootDir + objName;
    std::ofstream file(filename.c_str());
    if (file)
    {
        printf("Writing %s...\n", filename.c_str());
        mesh.writeObj(&file);
        file.close();
    }


    // calculate camera.
    double midX = (maxX + minX) / 2;
    double midY = minY + (maxY - minY) * 0.3;
    double midZ = (maxZ + minZ) / 2;
    double longest = std::max(std::max(maxX - minX, maxY - minY), maxZ - minZ) * 2.3;
    Vector3D target({ midX, midY, midZ });
    Vector3D origin({ 0.3,0.5,1 });
    origin.normalize();
    origin = origin * longest + target;

    // writing the xml file.
    char xmlname[256];
    snprintf(xmlname, sizeof(xmlname), "frame_%06d.xml", frameCnt);
    std::string xmlfilename = rootDir + std::string(xmlname);
    std::ofstream xmlfile(xmlfilename.c_str());
    if (xmlfile)
    {
        std::cout << "Writing " << xmlfilename << "...\n";
        xmlfile << "<scene version=\"0.5.0\">";
        xmlfile << "<integrator type=\"volpath_simple\">";
        xmlfile << "<integer name=\"maxDepth\" value=\"20\"/>";
        xmlfile << "</integrator>";
        xmlfile << "<sensor type=\"perspective\">";
        xmlfile << "<transform name=\"toWorld\">\n";
        xmlfile << "<lookat target=\"" << target.x << "," << target.y << "," << target.z
                << "\" origin=\"" << origin.x << "," << origin.y << "," << origin.z
                << "\" up=\"" << 0.0 << "," << 1.0 << "," << 0.0 << "\"/>\n";
        xmlfile << "</transform>";
        xmlfile << "<sampler type=\"ldsampler\">";
        xmlfile << "<integer name=\"sampleCount\" value=\"512\"/>";
        xmlfile << "</sampler>";
        xmlfile << "<film type=\"ldrfilm\">";
        xmlfile << "<integer name=\"width\" value=\"800\"/>";
        xmlfile << "<integer name=\"height\" value=\"600\"/>";
        xmlfile << "<string name=\"pixelFormat\" value=\"rgb\"/>";
        xmlfile << "</film>";
        xmlfile << "</sensor>";
        xmlfile << _sceneXml;
        xmlfile << "<emitter type=\"envmap\" id=\"envmapLight\">";
        xmlfile << "<string name=\"filename\" value=\"../envmap.exr\"/>";
        xmlfile << "<float name=\"scale\" value=\"2.75\"/>";
        xmlfile << "</emitter>";
        xmlfile << "<shape type=\"obj\" id=\"water\">";
        xmlfile << "<string name=\"filename\" value=\"" << objName << "\"/>";
        xmlfile << "<bsdf type=\"dielectric\">";
        xmlfile << "<float name=\"intIOR\" value=\"1.33\"/>";
        xmlfile << "<float name=\"extIOR\" value=\"1.0\"/>";
        xmlfile << "</bsdf>";
        xmlfile << "<medium name=\"interior\" type=\"homogeneous\">";
        xmlfile << "<rgb name=\"sigmaS\" value=\"0, 0, 0\"/>";
        xmlfile << "<rgb name=\"sigmaA\" value=\"4, 1.7, 1.5\"/>";
        xmlfile << "</medium>";
        xmlfile << "</shape>";
        xmlfile << "</scene>";
        xmlfile.close();
    }
    else
        std::cout << "Failed to save the file:" << filename << std::endl;*/
}

float Eulerfluid1::smoothStep(float edge0, float edge1, float x)
{
    //float t = clamp((x - edge0) / (edge1 - edge0), 0.f, 1.f);
    //return t * t * (3.f - 2.f * t);
    return 0;
}

void Eulerfluid1::update(float elapsedTime)
{
    LOG_INFO<<"test 1111";
}
