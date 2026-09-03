#include "gmsh_session.hpp"

#include <gmsh.h>

GmshSession::GmshSession()
{
    gmsh::initialize();
}

GmshSession::~GmshSession()
{
    gmsh::finalize();
}
