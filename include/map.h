#ifndef MAP_H
#define MAP_H

#include <QImage>
#include <QString>

class Map
{
private:
    Map();
    QImage Image;
    QString Image_Name;
public:
    QImage Load_Image();
    QString Get_Image_Name();
    void Set_Image(QString Image_Path);
    void Set_Iamge_Name(QString iImage_Name);
};

#endif // MAP_H
