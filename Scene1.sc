
# r -> read mesh ( mesh file name / mesh name )
# $ -> add single model ( mesh name / pos.x / pos.y / pos.z / rot.x / rot.y / rot.z / scale / fill / cull )
# x -> Coord Reder Mode ( a == Render line and XZ , l = Render Line only , s = Render side only)
Coord a

Mesh sphere.obj sphere
Mesh teapot.obj teapot

Model		sphere 10	100	10	0 0 0 1		t t
Hierarchy	teapot 10	0	0	0 0 0 2		t t
Hierarchy	sphere 10	0	0	0 0 0 3		t t


Model teapot 100 100 -100 0 0 0 7 t t


# Hierarchy
X