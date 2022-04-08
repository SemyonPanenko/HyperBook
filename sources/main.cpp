#include "headers/InnerStructure/Application.h"
#include "headers/ConsoleVisInt/ConsoleVisualizer.h"
#include "headers/ConsoleVisInt/ConsoleInterface.h"
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

    Application* app = new Application(bm, pm);

    std::cout << "Generated application\n";

    ConsoleInterface* ci = new ConsoleInterface(app);

    app->run();

    ci->run();


    delete cbv;
    delete cpv;
    delete bm;
    delete pm;
    delete app;
    delete ci;

}