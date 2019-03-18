/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_blur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:47:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/18 23:17:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
#define filterWidth 3
#define filterHeight 3

 double filter[filterHeight][filterWidth] =
{
   0, 0, 0,
   0, 1, 0,
   0, 0, 0
};

double factor = 1.0;
double dimmed = 0.0;

int main(int argc, char *argv[])
{
  //load the image into the buffer
  unsigned long w = 0, h = 0;
  std::vector<ColorRGB> image;
  loadImage(image, w, h, "pics/photo3.png");
  std::vector<ColorRGB> result(image.size());

  //set up the screen
  screen(w, h, 0, "Filters");

  ColorRGB color; //the color for the pixels

  //apply the filter
  for(int x = 0; x < w; x++)
  for(int y = 0; y < h; y++)
  {
    double red = 0.0, green = 0.0, blue = 0.0;

    //multiply every value of the filter with corresponding image pixel
    for(int filterY = 0; filterY < filterHeight; filterY++)
    for(int filterX = 0; filterX < filterWidth; filterX++)
    {
      int imageX = (x - filterWidth / 2 + filterX + w) % w;
      int imageY = (y - filterHeight / 2 + filterY + h) % h;
      red += image[imageY * w + imageX].r * filter[filterY][filterX];
      green += image[imageY * w + imageX].g * filter[filterY][filterX];
      blue += image[imageY * w + imageX].b * filter[filterY][filterX];
    }

    //truncate values smaller than zero and larger than 255
    result[y * w + x].r = min(max(int(factor * red + dimmed), 0), 255);
    result[y * w + x].g = min(max(int(factor * green + dimmed), 0), 255);
    result[y * w + x].b = min(max(int(factor * blue + dimmed), 0), 255);
  }

  //draw the result buffer to the screen
  for(int y = 0; y < h; y++)
  for(int x = 0; x < w; x++)
  {
    pset(x, y, result[y * w + x]);
  }

  //redraw & sleep
  redraw();
  sleep();
}
*/

static int	add_fill_blur_mask(float *bmap, point size, float value)
{
	point	p;
	int		max_fill_range;
	int		fill_range;
	int		fill_cells;

	p.y = -1;
	fill_cells = 0;
	max_fill_range = (size.x % 2) ? 1 : 2;
	while (++(p.y) < size.y)
	{
		if (max_fill_range > size.x)
			max_fill_range = size.x;
		fill_cells += max_fill_range;
		p.x = (size.x - max_fill_range) / 2;
		fill_range = size.x - (p.x * 2);
		while (fill_range--)
			bmap[p.y * size.x + (p.x)++] = value;
		if (p.y < size.y / 2)
			max_fill_range += 2;
		else
			max_fill_range -= 2;
	}
	return (fill_cells);
}

static void	add_blur_proccesing(t_bhelp b)
{
	FColor		fc;
	SDL_Color	srcc;
	point		i;
	point		f;
	SDL_Color	outc;

	f.y = -1;
	fc = (FColor){0.0, 0.0, 0.0};
	while (++(f.y) < b.size.y && (f.x = -1))
		while (++(f.x) < b.size.x)
		{
			i.x = (b.p->x - b.size.x / 2 + f.x + WIN_X) % WIN_X;
			i.y = (b.p->y - b.size.y / 2 + f.y + WIN_Y) % WIN_Y;
			srcc.r = b.src[i.y * WIN_X + i.x] >> 16;
			srcc.g = (b.src[i.y * WIN_X + i.x] >> 8) & 0xff;
			srcc.b = b.src[i.y * WIN_X + i.x] & 0xff;
			fc.r += srcc.r * b.bmap[f.y * b.size.x + f.x];
			fc.g += srcc.g * b.bmap[f.y * b.size.x + f.x];
			fc.b += srcc.b * b.bmap[f.y * b.size.x + f.x];
		}
	outc.r = MIN(MAX((int)(b.factor * fc.r + b.dimm), 0), 255);
	outc.g = MIN(MAX((int)(b.factor * fc.g + b.dimm), 0), 255);
	outc.b = MIN(MAX((int)(b.factor * fc.b + b.dimm), 0), 255);
	b.src[b.p->y * WIN_X + b.p->x] = (outc.r << 16 | outc.g << 8 | outc.b);
}

void		wolf_blur(point size, iarr src, float value, float dimmed)
{
	float		bmap[size.y][size.x];
	point		p;
	float		factor;

	ft_bzero((float**)bmap, sizeof(float) * (size.y * size.x));
	factor = 1.0 / add_fill_blur_mask((float*)&(bmap[0][0]), size, value);
	p.y = -1;
	while (++(p.y) < WIN_Y && (p.x = -1))
		while (++(p.x) < WIN_X)
			add_blur_proccesing((t_bhelp){
				&p, src, (float*)&(bmap[0][0]), dimmed, factor, size});
}
