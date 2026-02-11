/*
*  Function main() of main.cpp is the driver of WaveScope.
*  It creates and displays the GUI and awaits user action.
*
*/
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <iostream>
#include "AudioFileSampler.h"
using namespace std;

int main(int argc, char *argv[]) {
    cout << "running WaveScope...\n";
    cout << "_cplusplus = " << __cplusplus << endl;

    //
	// Create the audio sampler and load the file to sample
	//
	AudioFileSampler sampler;

	try {
		sampler.load("resources/250Hz_44100Hz_16bit_05sec.wav");
	} catch (const std::exception& e) {
		cerr << e.what() << endl;
	}

    // Display to the console
    cout << "Number of samples = " << sampler.numSamples() << endl;

    // 
    // Time to get GUI.
    // Use Qt to implement the WaveScope UI.
    //
    QApplication app(argc, argv);

    // Create and configure the UI window
    QWidget w;
    w.setWindowTitle("WaveScope");
    w.resize(800, 600);
    w.move(100, 100);
    w.setStyleSheet("background-color: white;");

    // Give the window a box layout
    QVBoxLayout* layout = new QVBoxLayout(&w);

    //
    // Display the number of data samples in the opened file
    //
    QString text = QString("Number of samples: %1")
                   .arg(static_cast<qulonglong>(sampler.numSamples()));

    // Create and configure the label
    QLabel* label = new QLabel(text);
    label->setStyleSheet("font-size: 18px; color: black;");
    label->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // Add the label to the UI
    layout->addWidget(label);
    layout->addStretch(); // add some space below

    // Display the UI window
    w.show();

    return app.exec();
}

