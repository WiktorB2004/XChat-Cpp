#include "../include/app_windows.h"
#include "../include/server_connection.h"

LoginWindow::LoginWindow(ServerConnection *connection, QWidget *parent) : QMainWindow(parent)
{
    // Set the window title
    setWindowTitle("XChat - Login");

    // Create a QLabel to hold the background image
    QLabel *backgroundLabel = new QLabel(this);
    backgroundLabel->setScaledContents(true); // Ensure the image scales to fit the label

    // Set the background image
    QPixmap backgroundImage("assets/images/X.jpg");

    // Set a fixed size for the background label to ensure it fills the entire window
    backgroundLabel->setPixmap(backgroundImage.scaled(QSize{400, 400}, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

    // LOGIN FORM
    QLabel *serverIpLabel = new QLabel("Server ip:", this);
    QLineEdit *serverIpLineEdit = new QLineEdit(this);
    QLabel *usernameLabel = new QLabel("Username:", this);
    QLineEdit *usernameLineEdit = new QLineEdit(this);
    QLabel *passwordLabel = new QLabel("Password:", this);
    QLineEdit *passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    // Create a vertical layout for the form
    QVBoxLayout *formLayout = new QVBoxLayout;
    formLayout->addWidget(serverIpLabel);
    formLayout->addWidget(serverIpLineEdit);
    formLayout->addWidget(usernameLabel);
    formLayout->addWidget(usernameLineEdit);
    formLayout->addWidget(passwordLabel);
    formLayout->addWidget(passwordLineEdit);

    // Create a QPushButton for submission
    QPushButton *submitButton = new QPushButton("Submit", this);

    // Create a horizontal layout for the form and submission button
    QHBoxLayout *formMenuLayout = new QHBoxLayout;
    formMenuLayout->addStretch();
    formMenuLayout->addWidget(submitButton);
    formMenuLayout->addStretch();

    // Create a widget to hold the form layout and submission button
    QWidget *formMenuWidget = new QWidget;
    formMenuWidget->setLayout(formMenuLayout);

    // Create a widget to hold the form layout
    QWidget *formWidget = new QWidget;
    formWidget->setLayout(formLayout);

    // Create a vertical layout to center the form and submission button
    QVBoxLayout *centerLayout = new QVBoxLayout;
    centerLayout->addWidget(backgroundLabel);
    centerLayout->addWidget(formWidget);
    centerLayout->addWidget(formMenuWidget);
    centerLayout->setAlignment(Qt::AlignCenter);

    // Set layout for central widget of the main window
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(centerLayout);
    setCentralWidget(centralWidget);

    // Center the window on the screen
    QSize windowSize = sizeHint();
    QPoint centerPoint = QGuiApplication::primaryScreen()->geometry().center();
    move(centerPoint - QPoint(windowSize.width() / 2, windowSize.height() / 2));
    setGeometry(
        QGuiApplication::primaryScreen()->geometry().center().x() - width() / 2,
        QGuiApplication::primaryScreen()->geometry().center().y() - height() / 2,
        width(),
        height());
}

LoginWindow::~LoginWindow()
{
    // Destructor implementation
}