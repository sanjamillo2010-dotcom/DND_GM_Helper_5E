#include "../include/map.h"

Map::Map() {}

QImage Map::Load_Image() {
    return Image;
}

QString Map::Get_Image_Name() {
    return Image_Name;
}

void Map::Set_Image(QString Image_Path) {
    Image.load(Image_Path);
}

void Map::Set_Iamge_Name(QString iImage_Name) {
    Image_Name = iImage_Name;
}
