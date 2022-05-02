#include "headers/InnerStructure/Application.h"
#include "headers/ConsoleVisInt/ConsoleVisualizer.h"
#include "headers/ConsoleVisInt/ConsoleInterface.h"
#include "headers/InnerStructure/CommandHandler.h"
#include <iostream>
#include <ctime>

int main(int argc, char* argv[]) {

    std::srand(std::time(0));

    std::cout << "Launching main function\n";

    ConsoleBoardVisualizer* cbv = new ConsoleBoardVisualizer();

    std::cout << "Generated board visualizer\n";

    ConsoleProjectVisualizer* cpv = new ConsoleProjectVisualizer();

    std::cout << "Generated project visualizer\n";

    BoardManager* bm = new BoardManager(cbv);

    std::cout << "Generated board manager\n";

    ProjectManager* pm = new ProjectManager(cpv);

    std::cout << "Generated project manager\n";

    CommandHandler* ch = new CommandHandler();

    Application* app = new Application(bm, pm, ch);

    std::cout << "Generated application\n";

    ConsoleInterface* ci = new ConsoleInterface(ch);

    app->run();

    ci->run();

    delete cbv;
    delete cpv;
    delete bm;
    delete pm;
    delete app;
    delete ci;
    delete ch;

}