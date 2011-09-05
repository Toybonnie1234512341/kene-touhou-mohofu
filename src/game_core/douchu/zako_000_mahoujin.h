
/*---------------------------------------------------------
	�����͕핗 �` Toho Imitation Style.
	http://code.google.com/p/kene-touhou-mohofu/
	-------------------------------------------------------
	�����̃U�R
	-------------------------------------------------------
	"�����w2"		�����閂���w
	"�����w1"		�΂�܂��U�������w
	-------------------------------------------------------
	�n�`�Ɋ֘A����G
---------------------------------------------------------*/

/* ���Ԑݒ� */

//#define MAHOU_TIME_LIMIT_00_MAX	(0x1ff)
//#define MAHOU_TIME_LIMIT_00_MAX	(0x17f)
#define MAHOU_TIME_LIMIT_00_MAX 	(0x13f)
#define MAHOU_TIME_LIMIT_01_ADJ 	((int)(0x0ff/3))
#define MAHOU_TIME_LIMIT_02_ADJ 	(MAHOU_TIME_LIMIT_00_MAX - MAHOU_TIME_LIMIT_01_ADJ)
#define MAHOU_TIME_LIMIT_03_EPS 	(0x04)

/*---------------------------------------------------------
	�G�U�����Ȃ�
---------------------------------------------------------*/

static void attack_kougeki_mahoujin00(OBJ *src)
{
	/* �U�����Ȃ� */
}
/*---------------------------------------------------------
	1:�c�U���̃J�[�h
---------------------------------------------------------*/

static void attack_kougeki_mahoujin01(OBJ *src)
{
	/* �U���J�n�t���[������16�t���[���o�ߌ�� 1�񂾂��U�� */
	if ((MAHOU_TIME_LIMIT_02_ADJ-16) == src->jyumyou)
	{
		zako_shot_supeka(src, ZAKO_SPEKA_11_mahou_tate);
	}
}

/*---------------------------------------------------------
	2:�����_���΂�܂��U��("�����w2")�̃J�[�h
---------------------------------------------------------*/

static void attack_kougeki_mahoujin02(OBJ *src)
{
	if (0 < src->MAHOU_TEKI_wait2)
	{
		src->MAHOU_TEKI_wait1--;			/* �΂�܂��Ԋu�J�E���^ */
		if (src->MAHOU_TEKI_wait1 <= 0) 	/* �΂�܂��Ԋu�J�E���^ */
		{
			src->MAHOU_TEKI_wait1 = (8);/*(5) (�v���O�����������Ȃ��Ă镪�x������)*/
			src->MAHOU_TEKI_wait2--;
			voice_play(VOICE12_MAGICF_E_SHOT, TRACK06_ALEART_IVENT_02);/*�e�L�g�[*/
			zako_shot_supeka(src, ZAKO_SPEKA_12_mahou_random);
		}
	}
}

/*---------------------------------------------------------
	�Ƃ肠�������ʕ���
---------------------------------------------------------*/

static void attack_kougeki_mahoujin_common(OBJ *src)
{
			zako_shot_supeka(src, ZAKO_SPEKA_0f_mahou_common);

}
/*---------------------------------------------------------
	3:�����_���΂�܂��U��+���@�_��("�����w1")�̃J�[�h
---------------------------------------------------------*/

static void attack_kougeki_mahoujin03(OBJ *src)
{
		OBJ *zzz_player;
		zzz_player = &obj99[OBJ_HEAD_02_0x0900_KOTEI+FIX_OBJ_00_PLAYER];
	if (
			(src->cy256 > zzz_player->cy256)
	 || 	(src->cy256 > t256(100))
	)
	{
	//	src->time_out++;/* = ST01;*/
		src->jyumyou								= MAHOU_TIME_LIMIT_01_ADJ;	/* ������ */
			zako_shot_supeka(src, ZAKO_SPEKA_08_mahou_nerai);
	}
	{
		src->MAHOU_TEKI_wait1--;			/* �΂�܂��Ԋu�J�E���^ */
		if (src->MAHOU_TEKI_wait1 <= 0) 	/* �΂�܂��Ԋu�J�E���^ */
		{
			src->MAHOU_TEKI_wait1 = (25-((cg.game_difficulty)*5)); /* �΂�܂��Ԋu�J�E���^ */
			voice_play(VOICE12_MAGICF_E_SHOT, TRACK06_ALEART_IVENT_02);/*�e�L�g�[*/
			/* ���x�� 1.0-4.0�܂ł̗���(�����������ɕ΍�)�ɕύX */
//...			HATSUDAN_01_speed256						= ((ra_nd()&(1024-1))|(0x100))+t256(1.0);	/* �e�� */
			HATSUDAN_03_angle65536						= ((ra_nd()&(65536-1)));					/* �p�x */
			attack_kougeki_mahoujin_common(src);
		}
	}
}

/*---------------------------------------------------------
	4:�~��U���̃J�[�h(����)
	5:�~��U���̃J�[�h(���E)
	6:�~��U���̃J�[�h(�卶)
---------------------------------------------------------*/

static void attack_kougeki_mahoujin4564(OBJ *src)
//atic void attack_kougeki_mahoujin05(OBJ *src)
//atic void attack_kougeki_mahoujin06(OBJ *src)
{
	/* �U���J�n�t���[������16�t���[���o�ߌ�� 1�񂾂��U�� */
	//if ((MAHOU_TIME_LIMIT_02_ADJ-16) == src->time_out)
	//if (0 == (src->jyumyou&0x07))
	if ((cg.game_difficulty) >= (src->jyumyou&0x03))
	{
			zako_shot_supeka(src, (int)(((src->cx256)&0x07)|(0x10)) );
	}
}




/*---------------------------------------------------------
	�G�ړ�
---------------------------------------------------------*/
		#if 0
		{			attack_kougeki_mahoujin02(src); }	/* ("�����w2") �����閂���w */
		{			attack_kougeki_mahoujin03(src); }	/* ("�����w1") �΂�܂��U�������w */
		#endif

static void move_kougeki_mahoujin(OBJ *src)
{
	/* �o�� */
	if (MAHOU_TIME_LIMIT_02_ADJ < src->jyumyou)
	{
		src->color32 += 0x03000000; 		/*	src->alpha += 0x03;*/ /*4*/ /*fps_factor*/
	}
	/* �����蔻��A���� */
	else
	if (MAHOU_TIME_LIMIT_02_ADJ == src->jyumyou)
	{
		src->atari_hantei			= (1/*�X�R�A���p*/);	/* �����蔻�肠�� */
		/*(�����ŃX�R�A��ݒ肷��)*/
	}
	/* �U�� */
	else
	if (MAHOU_TIME_LIMIT_01_ADJ < src->jyumyou)
	{
	//	set_REG_DEST_XY(src);	/* �e��x256 y256 ���S���甭�e�B */
		/* �J�[�h�I�� */
		void (*aaa[8])(OBJ *src) =
		{
			attack_kougeki_mahoujin00,		/* �U�����Ȃ� */
			attack_kougeki_mahoujin01,		/* �c�e */
			attack_kougeki_mahoujin02,		/* �΂�܂� #01(�������A��"�����w2") */
			attack_kougeki_mahoujin03,		/* �΂�܂� #02(�������A��"�����w1") */
			attack_kougeki_mahoujin4564,		/* 8way�Ԓe(��) */
			attack_kougeki_mahoujin4564,		/* 8way�Ԓe(��) */
			attack_kougeki_mahoujin4564,		/* 8way�Ԓe(��) */
			attack_kougeki_mahoujin4564,		/* 8way�Ԓe */
		};
		(*aaa[ (int)((src->cx256)&0x07) ])(src);	/* �e�֐��ɕ��򂷂� */
	}
	/* �����蔻��A�Ȃ� */
	else
	if (MAHOU_TIME_LIMIT_01_ADJ == src->jyumyou)
	{
		src->atari_hantei			= (ATARI_HANTEI_OFF/*�X�R�A���p*/); 	/* �����蔻�薳�� */
		/*(�����蔻�薳��==�X�R�A�͖���)*/
	}
	/* ������ */
	else
	if (MAHOU_TIME_LIMIT_03_EPS < src->jyumyou) 	/*	if (0x04 0x00 > (unsigned int)(src->alpha))*/
	{
		src->color32 -= 0x03000000; 	/*	src->alpha += 0x03;*/ /*4*/ /*fps_factor*/
	}
	/* �����܂� */
	else
	{
	//	src->color32 = 0x00ffffff;		/*	src->alpha = 0x00;*/
		src->jyumyou = JYUMYOU_NASI;
	}
	/* �A�j�� (�h���) */
	{
		int sin_value_t256; 		//	sin_value_t256 = 0;
		int cos_value_t256; 		//	cos_value_t256 = 0;
		int256_sincos1024( (((src->jyumyou<<5)/*&(1024-1)*/)), &sin_value_t256, &cos_value_t256);
	//	src->cy256 = src->start_y256 + ((cos1024(((src->jyumyou<<5)&(1024-1))))<<2);
		src->cy256 = src->start_y256 + ((sin_value_t256)<<2);
	}
//	src->rotationCCW1024++;
//	mask1024(src->rotationCCW1024);
}

/*---------------------------------------------------------
	�G��ǉ�����
---------------------------------------------------------*/
static void add_common_mahoujin(GAME_COMMAND *l, OBJ *h)
{
	h->atari_hantei		= (ATARI_HANTEI_OFF/*�X�R�A���p*/); 	/* �����蔻�薳�� */
	/*(�����蔻��==�l���X�R�A)*/
	/* KETM�̑��΍��W�w��͔p�~�B��ʍ��W�w��ɂ��� */
	h->cx256						= (((short)l->user_x)<<8)|(((char)l->user_kougeki_type)&0x07);/* ��������C���^�[���[�u */
	h->start_y256					= (((short)l->user_y)<<8);
	//
	h->jyumyou						= MAHOU_TIME_LIMIT_00_MAX;/* SS00 �܂��� ST00 */

	h->MAHOU_TEKI_wait1 			= (10); 	/*+90*/ /* */
	h->MAHOU_TEKI_wait2 			= (5);		/* �ő�܉� */
	h->color32						= 0x00ffffff;	/*	h->alpha				= 0x02 0x00;*/
}

/* �΂�܂��U�������w */	/* "�����w1" "GROUNDER",*/
static void regist_zako_000_mahoujin1(GAME_COMMAND *l, OBJ *h)// MAHOUJIN A
{
	{
		h->m_Hit256R				= ZAKO_ATARI04_PNG;/* �����蔻��T�C�Y��ς��� */
		h->callback_loser			= item_create_000_kougeki_mahoujin;
//		h->MAHOU_TEKI_wait1 		= 100;
	//	h->MAHOU_TEKI_wait2 		= 0;/* ���g�p */
	}
	add_common_mahoujin(l, h);
}

/* �����閂���w */	/* "�����w2" "MAGICF",*/
static void regist_zako_001_mahoujin2(GAME_COMMAND *l, OBJ *h)// MAHOUJIN B
{
	{
		h->m_Hit256R				= ZAKO_ATARI16_PNG;
//		h->MAHOU_TEKI_wait1 		= 10/*+90*/;
	//	h->MAHOU_TEKI_wait2 		= (5);		/* �ő�܉� */
	}
	add_common_mahoujin(l, h);
}
//		/*data->base.*/h->base_hp	= (9999);/* �|���Ȃ� */
//		/*data->base.*/h->base_hp		+= (8*25)+(1/*di fficulty*/<<(3/*4*/+3));	//+(di fficulty*15)
//		/*data->base.*/h->base_score	= score(200*2);