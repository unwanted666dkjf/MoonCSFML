#ifndef MOON_CSFML_GRAPHICS_MOON_PRIMITIVE_TYPE_H
#define MOON_CSFML_GRAPHICS_MOON_PRIMITIVE_TYPE_H


#ifdef __cplusplus
extern "C" {
#endif


enum
{
    moon_PrimitiveType_Points,        //!< List of individual points
    moon_PrimitiveType_Lines,         //!< List of individual lines
    moon_PrimitiveType_LineStrip,     //!< List of connected lines, a point uses the previous point to form a line
    moon_PrimitiveType_Triangles,     //!< List of individual triangles
    moon_PrimitiveType_TriangleStrip, //!< List of connected triangles, a point uses the two previous points to form a triangle
    moon_PrimitiveType_TriangleFan,   //!< List of connected triangles, a point uses the common center and the previous point to form a triangle
    moon_PrimitiveType_Quads,         //!< List of individual quads (deprecated, don't work with OpenGL ES)

    // Deprecated names
    moon_PrimitiveType_LinesStrip     = moon_PrimitiveType_LineStrip,     //!< \deprecated Use LineStrip instead
    moon_PrimitiveType_TrianglesStrip = moon_PrimitiveType_TriangleStrip, //!< \deprecated Use TriangleStrip instead
    moon_PrimitiveType_TrianglesFan   = moon_PrimitiveType_TriangleFan    //!< \deprecated Use TriangleFan instead
};


#ifdef __cplusplus
}
#endif


#endif
