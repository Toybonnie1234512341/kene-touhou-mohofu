
/*---------------------------------------------------------
	�����͕핗 �` Toho Imitation Style.
	http://mohou.huuryuu.com/
	-------------------------------------------------------
---------------------------------------------------------*/

/*
    SDL_mixer:  An audio mixer library based on the SDL library
    Copyright (C) 1997-2004 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Sam Lantinga
    slouken@libsdl.org
*/

/* $Id: wavestream.h,v 1.6 2004/01/04 17:37:04 slouken Exp $ */

/* This file supports streaming WAV files, without volume adjustment */

#include <stdio.h>

typedef struct
{
	FILE *wavefp;
	long  start;
	long  stop;
	PSPL_AUDIO_CONVERT cvt;
} WAVStream;

/* Initialize the WAVStream player, with the given mixer settings
   This function returns 0, or -1 if there was an error.
 */
extern int WAVStream_Init(PSPL_AUDIO_SPEC *mixer);

/* Unimplemented */
extern void WAVStream_SetVolume(int volume);

/* Load a WAV stream from the given file */
extern WAVStream *WAVStream_LoadSong(const char *file, const char *magic);

/* Start playback of a given WAV stream */
extern void WAVStream_Start(WAVStream *wave);

/* Play some of a stream previously started with WAVStream_Start() */
extern void WAVStream_PlaySome(u8 *stream, int len);

/* Stop playback of a stream previously started with WAVStream_Start() */
extern void WAVStream_Stop(void);

/* Close the given WAV stream */
extern void WAVStream_FreeSong(WAVStream *wave);

/* Return non-zero if a stream is currently playing */
extern int WAVStream_Active(void);

