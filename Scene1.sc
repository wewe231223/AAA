# Mesh -> read mesh ( mesh file name / mesh name )
# Model -> add single model ( mesh name / pos.x / pos.y / pos.z / rot.x / rot.y / rot.z / scale / fill / cull )
# x -> Coord Reder Mode ( a == Render line and XZ , l = Render Line only , s = Render side only)
Coord l

Mesh sphere.obj sphere
Mesh teapot.obj teapot



Model sphere 0 0 0 0 0 0 10 t t
<Component> Circle 0 1.2 0 4.24 0 1 0 0
{

Model sphere 3 0 -3 0 0 0 0.3 t t
<Component> Circle 0 0 0 5 1 0 1 0
<Animation> Revolution 5 1 0 1

{
	Model sphere 5 0 0 0 0 0 0.5 t t 
	<Animation> Revolution 5 0 1 0
}


Model sphere -3 0 -3 0 0 0 0.3 t t
<Animation> Revolution 5 1 0 -1
{
	Model sphere 5 0 0 0 0 0 0.5 t t 
	<Animation> Revolution 5 0 1 0
}


Model sphere 3 1 3 0 0 0 0.3 t t
<Animation> Revolution 5 0 1 0
{
	Model sphere 5 0 0 0 0 0 0.5 t t 
	<Animation> Revolution 5 0 1 0
}


}
EndFile