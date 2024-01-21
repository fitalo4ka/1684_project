#include <QtWidgets>

class FigureWidget : public QWidget {
 public:
  FigureWidget(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawRect(10, 20, 130, 100);
  }
};

class FigureImage : public QWidget {
 public:
  FigureImage(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QImage image(180, 140, QImage::Format_RGB32);
    image.fill(qRgb(255, 255, 255));
    QPainter painter(&image);
    painter.drawRect(10, 20, 130, 100);
    QPainter widgetPaint(this);
    widgetPaint.drawImage(0, 0, image);
  }
};

class FigurePixmap : public QWidget {
 public:
  FigurePixmap(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QPixmap pixmap(180, 140);
    pixmap.fill(qRgb(255, 255, 255));
    QPainter painter(&pixmap);
    painter.drawRect(10, 20, 130, 100);
    QPainter widgetPaint(this);
    widgetPaint.drawPixmap(0, 0, pixmap);
  }
};

class FigurePicture : public QWidget {
 public:
  FigurePicture(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QPicture picture;
    QPainter painter(&picture);
    painter.drawRect(10, 20, 130, 100);
    painter.end();
    QPainter widgetPaint(this);
    widgetPaint.drawPicture(0, 0, picture);
  }
};

class FigureGraphicsScene : public QWidget {
 public:
  FigureGraphicsScene(QWidget *p = nullptr) : QWidget(p) {}
  void paintEvent(QPaintEvent *e) {
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 160, 120);
    QGraphicsRectItem *rect = new QGraphicsRectItem(10, 20, 130, 100);
    scene.addItem(rect);
    QGraphicsView view(&scene);
    view.setGeometry(0, 0, 130, 100);
    QPainter widgetPaint(this);
    scene.render(&widgetPaint, QRectF(0, 0, 130, 100));
  }
};

class FigureOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
 public:
  FigureOpenGLWidget(QWidget *p = nullptr) : QOpenGLWidget(p) {}
  void initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  }
  void resizeGL(int w, int h) { glViewport(0, 0, w, h); }
  void paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    float width = 0.6f, height = 0.4f;

    // Нижняя грань
    glBegin(GL_LINE_LOOP);
    glVertex2f(-width, -height);
    glVertex2f(width, -height);
    glEnd();

    // Верхняя грань
    glBegin(GL_LINE_LOOP);
    glVertex2f(-width, height);
    glVertex2f(width, height);
    glEnd();

    // Левая грань
    glBegin(GL_LINE_LOOP);
    glVertex2f(-width, -height);
    glVertex2f(-width, height);
    glEnd();

    // Правая грань
    glBegin(GL_LINE_LOOP);
    glVertex2f(width, -height);
    glVertex2f(width, height);
    glEnd();
  }
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QWidget window;
  window.resize(1000, 300);
  window.setStyleSheet("background-color: rgb(255, 255, 255);");

  QHBoxLayout nameLayout;
  QLabel *textWidget = new QLabel("QWidget");
  textWidget->setFixedSize(180, 20);
  nameLayout.addWidget(textWidget);
  QLabel *textImage = new QLabel("QImage");
  textImage->setFixedSize(180, 20);
  nameLayout.addWidget(textImage);
  QLabel *textPixmap = new QLabel("QPixmap");
  textPixmap->setFixedSize(180, 20);
  nameLayout.addWidget(textPixmap);
  QLabel *textPicture = new QLabel("QPicture");
  textPicture->setFixedSize(180, 20);
  nameLayout.addWidget(textPicture);
  QLabel *textGraphicsScene = new QLabel("QGraphicsScene");
  textGraphicsScene->setFixedSize(180, 20);
  nameLayout.addWidget(textGraphicsScene);
  QLabel *textOpenGLWidget = new QLabel("QOpenGLWidget");
  textOpenGLWidget->setFixedSize(180, 20);
  nameLayout.addWidget(textOpenGLWidget);

  QHBoxLayout layout;
  FigureWidget *widget = new FigureWidget;
  layout.addWidget(widget);
  FigureImage *image = new FigureImage;
  layout.addWidget(image);
  FigurePixmap *pixmap = new FigurePixmap;
  layout.addWidget(pixmap);
  FigurePicture *picture = new FigurePicture;
  layout.addWidget(picture);
  FigureGraphicsScene *graphicsScene = new FigureGraphicsScene;
  layout.addWidget(graphicsScene);
  FigureOpenGLWidget *openGlWidget = new FigureOpenGLWidget;
  layout.addWidget(openGlWidget);
  window.setWindowTitle("test task");

  QVBoxLayout mainLayout(&window);
  mainLayout.addLayout(&nameLayout);
  mainLayout.addLayout(&layout);

  window.show();
  return app.exec();
}