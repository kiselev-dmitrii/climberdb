#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
        QApplication application(argc, argv);
        QApplication::setOrganizationName("Climber");
        QApplication::setApplicationName("ClimberDB");

        MainWindow mainWindow;
        mainWindow.show();
        
        return application.exec();
}
