# Mesh -> read mesh ( mesh file name / mesh name )
# Model -> add single model ( mesh name / pos.x / pos.y / pos.z / rot.x / rot.y / rot.z / scale / fill / cull )
# x -> Coord Reder Mode ( a == Render line and XZ , l = Render Line only , s = Render side only)
Coord l

Mesh sphere.obj sphere
Mesh teapot.obj teapot

Model sphere 0 0 0 0 0 0 5 t t
{
	Model sphere 10 0 0 0 0 0 0.5 t t 
}





EndFile