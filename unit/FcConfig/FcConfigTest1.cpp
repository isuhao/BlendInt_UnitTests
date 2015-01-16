#include "FcConfigTest1.hpp"
#include <BlendInt/Font/FcPattern.hpp>
#include <BlendInt/Font/FcObjectSet.hpp>
#include <BlendInt/Font/FcConfig.hpp>

using namespace BlendInt;

FcConfigTest1::FcConfigTest1()
: testing::Test()
{
	// TODO: add constructor code
}

FcConfigTest1::~FcConfigTest1()
{
	// TODO: add destructor code
}

/**
 * test Foo() method
 *
 * Expected result: 
 */
TEST_F(FcConfigTest1, List1)
{
	Fc::Pattern pattern;

	RefPtr<Fc::ObjectSet> os = Fc::ObjectSet::build(FC_FAMILY, FC_STYLE, FC_FILE, (char*)NULL);


	if(os) {
		fprintf(stdout, "object set\n");
	}

	const FcChar8 *format = (const FcChar8 *) "%{=fclist}\n";

	RefPtr<Fc::FontSet> fs = Fc::Config::list(0, pattern, *os);

	for(int i = 0; i < fs->fontset()->nfont; i++)
	{
		FcChar8 *s;

		s = FcPatternFormat (fs->fontset()->fonts[i], format);
		if (s)
		{
			printf ("%d: %s", i, s);
			FcStrFree (s);
		}
	}

	FcFini();

	ASSERT_TRUE(true);
}
