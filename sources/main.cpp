#include "headers/Application.h"
#include "headers/ConsoleVisualizer.h"
#include <iostream>

int main(int argc, char* argv[]) {

    std::cout << "Launching main function\n";

    ConsoleBoardVisualizer* cbv = new ConsoleBoardVisualizer();

    std::cout << "Generated board visualizer\n";

    ConsoleProjectVisualizer* cpv = new ConsoleProjectVisualizer();

    std::cout << "Generated project visualizer\n";

    BoardManager* bm = new BoardManager(cbv);

    std::cout << "Generated board manager\n";

    ProjectManager* pm = new ProjectManager(cpv);

    std::cout << "Generated project manager\n";

    Application app(bm, pm);

    std::cout << "Generated application\n";

    app.run();

    delete cbv;
    delete cpv;
    delete bm;
    delete pm;

}