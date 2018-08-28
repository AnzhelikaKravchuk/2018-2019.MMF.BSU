<Query Kind="Program" />

void Main()
{
	Shape[] shapes = new Shape[] 
	{new Square(), new Triangle(), new Circle(), 
	new Square(), new Triangle(), new Circle()};
	
	for (int i = 0; i < shapes.Length; i++)
	{
		ClientCode(shapes[i]);
	}
	
}

public abstract class Shape
{
	public abstract void Draw();
}

public class Circle : Shape
{
	public override void Draw() => "Circle".Dump();
}

public class Square : Shape
{
	public override void Draw() => "Square".Dump();
}

public class Triangle : Shape
{
	public override void Draw() => "Triangle".Dump();
}

public static void ClientCode(Shape shape) => shape.Draw();