#include "pch.h"
#include "TextureTest.h"




void testTexture()
{
}

class ResourceLocation {
    int mFileSystem;
    char unk[4];
    void* mPath[4];
    void* mPathHash;
    void* mFullHash;
};
class IsotropicFaceData {
    unsigned int mFaceTextureIsotropic;
    unsigned int mIsotropicFaceEnabled;
};

class TextureUVCoordinateSet {
    int weight;
    int u0;
    int v0;
    int u1;
    int v1;
    short _texSizeW;
    short _texSizeH;
    ResourceLocation sourceFileLocation; // 0x24
    IsotropicFaceData mIsotropicFaceData; // 0x80
    short unk = -1;
};

THook(TextureUVCoordinateSet&, "?getTextureUVCoordinateSet@Item@@SA?AUTextureUVCoordinateSet@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z",
    TextureUVCoordinateSet* _this, string& str, int a) {
    auto& rtn = original(_this, str, a);
    return rtn;
}
