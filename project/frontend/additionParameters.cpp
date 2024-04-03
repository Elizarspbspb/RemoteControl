/*#include <QtWidgets>

class MainParamSelector : public QMainWindow {
    Q_OBJECT

public:
    MainParamSelector(QWidget *parent = nullptr) : QMainWindow(parent) {
        QVBoxLayout *layout = new QVBoxLayout;
        //QBoxLayout *layout = new QBoxLayout;

        comboBox = new QComboBox;
        comboBox->addItem("Image 1");
        comboBox->addItem("Image 2");
        comboBox->addItem("Image 3");
        comboBox->addItem("Image 4");
        comboBox->addItem("Image 5");
        layout->addWidget(comboBox);

        imageLabel = new QLabel;
        imageLabel->setAlignment(Qt::AlignCenter);


        layout->addWidget(imageLabel);

        QWidget *centralWidget = new QWidget;
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainParamSelector::changeImage);
    }

private slots:
    void changeImage(int index) {
        switch (index) {
            case 0:
                imageLabel->setPixmap(image1);
                break;
            case 1:
                imageLabel->setPixmap(image2);
                break;
            case 2:
                imageLabel->setPixmap(image3);
                break;
            case 3:
                imageLabel->setPixmap(image4);
                break;
            case 4:
                imageLabel->setPixmap(image5);
                break;
            default:
                break;
        }
    }

private:
    QComboBox *comboBox;
    QLabel *imageLabel;
    QPixmap image1{":/images/Computer.png"};
    QPixmap image2{":/images/Notepad.png"};
    QPixmap image3{":/images/Printer.png"};
    QPixmap image4{":/images/Router.png"};
    QPixmap image5{":/images/Server.png"};
}; */
