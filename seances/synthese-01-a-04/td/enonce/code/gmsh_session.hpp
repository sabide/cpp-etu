#ifndef GMSH_SESSION_HPP
#define GMSH_SESSION_HPP

class GmshSession {
public:
    GmshSession();
    ~GmshSession();

    GmshSession(const GmshSession&) = delete;
    GmshSession& operator=(const GmshSession&) = delete;
};

#endif
