all:
	g++ src/Main.cpp src/view/cycle.cpp src/view/dashboard.cpp src/view/render.cpp src/view/road.cpp src/view/cars.cpp src/controller/controller.cpp -o output -lGL -lglut
clean:
	$(RM) output
