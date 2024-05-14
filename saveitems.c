#include "solong.h"

static void	save_position_struct(t_matrix	*mappa, int y, int x, char type)
{
   if (type == 'P')
   {
    	mappa->p.nitems = 'P';
    	mappa->p.xmap = x;
    	mappa->p.ymap = y;
   }
   else if (type == 'E')
   {
		mappa->p.nitems = 'E';
    	mappa->p.xmap = x;
    	mappa->p.ymap = y;
   }
   else if (type == 'N')
   {
		mappa->p.nitems = 'N';
    	mappa->p.xmap = x;
    	mappa->p.ymap = y;
   }
}

void savePosition(t_matrix *mappa)
{
   int y;
   int x;

   y = 0;
   while (y < mappa->maxY )
	{
		x = 0;
		while (x < mappa->maxX )
		{
			if (mappa->map[y][x] == 'P')
            save_position_struct(mappa, y, x,'P');
		 if (mappa->map[y][x] == 'N')
			save_position_struct(mappa, y, x,'N');
         if (mappa->map[y][x] == 'C' )
            save_position_struct(mappa, y, x,'C');
         if (mappa->map[y][x] == 'E')
            save_position_struct(mappa, y, x,'E');
			x++;
		}
		y++;
	}
}