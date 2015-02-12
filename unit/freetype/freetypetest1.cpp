#include "FreetypeTest1.hpp"
#include <font/ft-face.hpp>
#include <gui/glyph.hpp>

using namespace BlendInt;
using namespace BlendInt::Ft;

FreetypeTest1::FreetypeTest1()
: testing::Test()
{
	// TODO: add constructor code
}

FreetypeTest1::~FreetypeTest1()
{
	// TODO: add destructor code
}

TEST_F(FreetypeTest1, Library1)
{
	Library lib;
	Face face;
	// FTStroker stroker;

	lib.Init();
	lib.SetLcdFilter(FT_LCD_FILTER_DEFAULT);

	face.New(lib, "/usr/share/fonts/adobe-source-han-sans-cn/SourceHanSansCN-Regular.otf");
	face.set_char_size(24 << 6, 0, 96, 0);

	FT_GlyphSlot slot = face.face()->glyph;

	for(int i = 33; i < 127; i++) {
		face.load_char(i, FT_LOAD_RENDER);

		DBG_PRINT_MSG("bitmap left: %d,"
						"bitmap top: %d,"
						"bitmap width: %d,"
						"bitmap height: %d,"
						"advance x: %ld",
						slot->bitmap_left,
						slot->bitmap_top,
						slot->bitmap.width,
						slot->bitmap.rows,
						slot->advance.x >> 6);

	}

	DBG_PRINT_MSG("max advance: %ld, max height: %ld or %ld",
					face.face()->size->metrics.max_advance >> 6,
					(face.face()->size->metrics.ascender >> 6) - (face.face()->size->metrics.descender >> 6),
					face.face()->size->metrics.height >> 6);

	/*
	stroker.New(lib);

	stroker.Done();
	*/

	face.Done();
	lib.Done();

	ASSERT_TRUE(true);
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
/*
TEST_F(FreetypeTest1, Open01) {

	Freetype test;

	//test.Open("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 12, 96);
	test.Open("/home/zhanggyb/.fonts/s/STKaiti.ttf", 12, 96);

	fprintf(stdout, "height: %d, max advance: %d\n", test.height(), test.max_advance());

	fprintf(stdout, "sizeof Glyph: %ld, size of GlyphExt: %ld\n", sizeof(Glyph), sizeof(GlyphExt));

	ASSERT_TRUE(test.valid());
}
*/

/*
TEST_F(FreetypeTest1, Kerning02) {

	Freetype test;

	test.Open("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 12, 96);

	if(test.IsUseKerning()) {

		fprintf(stdout, "font is using kerning\n");
		FT_UInt left;
		FT_UInt right;
		FT_Vector kerning = {0, 0};

		for(char lc = 'a'; lc < 'z'; lc++) {

			for(char rc = 'a'; rc < 'z'; rc++) {

				left = test.GetCharIndex(lc);
				right = test.GetCharIndex(rc);

				kerning = test.GetKerning(left, right);

				if(kerning.x > 0) {
					fprintf (stdout, "Kerning of %c and %c is %ld\n", lc, rc, kerning.x);
				}
			}

		}

	}

	ASSERT_TRUE(test.valid());
}
*/
