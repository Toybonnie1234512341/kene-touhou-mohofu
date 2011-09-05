
/*---------------------------------------------------------
	�����͕핗 �` Toho Imitation Style.
	http://code.google.com/p/kene-touhou-mohofu/
	-------------------------------------------------------
	�����̃U�R
	-------------------------------------------------------
		"�d��1",		"FAIRY",
	-------------------------------------------------------
	user_x: 	���x256[speed256]
	user_y: 	���ʒu[pixel]
---------------------------------------------------------*/

/*---------------------------------------------------------
	�G�ړ�
---------------------------------------------------------*/

static void move_ao_yousei1(OBJ *src)
{
	if (512 > src->jyumyou) 	/* ���E */
	{
		src->speed256 += (2);/*(2+1)*/
		src->tmp_angleCCW1024 += (4);
		if (511 < src->tmp_angleCCW1024)
		{
			src->tmp_angleCCW1024 = (511);/*�^��*/
		}
		gamen_gai_nara_zako_osimai(src);/* ��ʊO�Ȃ炨���܂� */
	}
	else	/* �U�� */
	{
		if ((512+50)==src->jyumyou)
		{
			if (0!=(cg.game_difficulty))
			{
				zako_shot_supeka(src, ZAKO_SPEKA_1c_ao1);
			}
		}
//		ca se 0x40: /*not_break;*/	/*0x40==064 0x46==070*/
//		ca se 0x80: /*not_break;*/	/*0x80==128 0x78==120*/
//		ca se 0xa0: /*not_break;*/	/*0x  ==170 0xaa==170*/
//		ca se 0xc0: 				/*0x  ==220 0xdc==220*/
		if (0x00==(src->jyumyou&(0x1f)))/* 8�� */
		{
			if (0!=(cg.game_difficulty))
			{
				zako_shot_supeka(src, ZAKO_SPEKA_1b_ao2);
			}
		}
		src->speed256 -= (5/*5*/);
		if (1 > src->speed256)
		{
			src->speed256 = 1;
		}
	}
	/*�ȉ�rwingx.c�Ɠ���*/
	//------------------
	HATSUDAN_01_speed256	= (src->speed256);
	HATSUDAN_03_angle65536	= deg1024to65536((src->tmp_angleCCW1024));
	sincos256();/*(�j�󃌃W�X�^�����̂Œ���)*/
	src->cx256 += REG_03_DEST_Y;//sin_value_t256 // ��CCW�̏ꍇ(�ECW�̏ꍇ�Ƃ�xy���t)
	src->cy256 += REG_02_DEST_X;//cos_value_t256 // ��CCW�̏ꍇ(�ECW�̏ꍇ�Ƃ�xy���t)
	//------------------
	/* �A�j���[�V���� */
	zako_anime_type02(src);
}


/*---------------------------------------------------------
	�G��ǉ�����
---------------------------------------------------------*/

static void regist_zako_019_ao_yousei1(GAME_COMMAND *l, OBJ *h)
{
//	h->cx256				= ((l->user_x)<<8);
//	h->cy256				= ((l->user_y)<<8);
	h->cy256				+= t256(-128);
//
	h->speed256 			= t256(2.0);

	h->tmp_angleCCW1024 	= (0);/* �^�� */
	h->jyumyou				= (512+320);
}