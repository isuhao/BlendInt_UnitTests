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

TEST_F(FcConfigTest1, Pattern1)
{
	FcInit();
	//Fc::Config config = Fc::Config::init_load_config_and_fonts();

	//Fc::Pattern pattern1;
	Fc::Pattern pattern1 = Fc::Pattern::name_parse((const FcChar8*)"Source Code Pro:style=Bold:size=24");

	pattern1.print();

	Fc::Config::substitute(0, pattern1, FcMatchPattern);
	pattern1.default_substitute();

	//pattern1.print();

	FcResult result;
	Fc::Pattern match1 = Fc::Config::match (0, pattern1, &result);

	if(match1) {
		match1.print();
	}

	Fc::Pattern pattern2 = match1;
	//pattern2.print();

	bool ret = pattern2 == match1;

	//pattern1.destroy();
	match1.destroy();
	pattern2.destroy();

	//config.destroy();

	FcFini();

	ASSERT_TRUE(ret);
}

/*

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

TEST_F(FcConfigTest1, Match1)
{
	Fc::Pattern pattern1;
	pattern1.add(FC_SIZE, 12);
	pattern1.add(FC_WEIGHT, FC_WEIGHT_REGULAR);
	pattern1.add(FC_SLANT, FC_SLANT_ROMAN);
	pattern1.add(FC_FAMILY, "Arial Unicode MS");

	Fc::Config::substitute(0, pattern1, FcMatchPattern);
	pattern1.default_substitute();

	FcResult result;
	Fc::Pattern match1 = Fc::Config::match (0, pattern1, &result);

	if(match1) {
		match1.print();
	}

	Fc::Pattern pattern2;
	pattern2.add(FC_SIZE, 14);
	pattern2.add(FC_WEIGHT, FC_WEIGHT_REGULAR);
	pattern2.add(FC_SLANT, FC_SLANT_ROMAN);
	pattern2.add(FC_FAMILY, "Arial Unicode MS");

	Fc::Config::substitute(0, pattern2, FcMatchPattern);
	pattern2.default_substitute();

	Fc::Pattern match2 = Fc::Config::match (0, pattern2, &result);

	if(match2) {
		match2.print();
	}

	if(match1 == match2) {
		fprintf(stdout, "Equal");
	}

	fprintf(stdout, "match1 hash: 0x%X\n", match1.hash());
	fprintf(stdout, "match2 hash: 0x%X\n", match2.hash());
	
	ASSERT_TRUE(true);
}

*/
