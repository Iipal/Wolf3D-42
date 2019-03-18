/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_blur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:47:08 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/18 20:17:33 by tmaluh           ###   ########.fr       */
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
double bias = 0.0;

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
    result[y * w + x].r = min(max(int(factor * red + bias), 0), 255);
    result[y * w + x].g = min(max(int(factor * green + bias), 0), 255);
    result[y * w + x].b = min(max(int(factor * blue + bias), 0), 255);
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

static void	add_fill_blur_mask(float *bmap, point size, float value)
{
	point	p;
	int		max_fill_range;
	int		fill_range;

	p.y = -1;
	max_fill_range = (size.x % 2) ? 1 : 2;
	while (++(p.y) < size.y)
	{
		if (max_fill_range > size.x)
			max_fill_range = size.x;
		p.x = (size.x - max_fill_range) / 2;
		fill_range = size.x - (p.x * 2);
		while (fill_range--)
			bmap[p.y * size.x + (p.x)++] = value;
		if (p.y < size.y / 2)
			max_fill_range += 2;
		else
			max_fill_range -= 2;
	}
}

void		wolf_blur(point size, iarr src, float value)
{
	float		bmap[size.y][size.x];
	FColor		fcolor;
	point		psrc;
	point		pfilter;
	point		pimg;
	SDL_Color	src_color;
	SDL_Color	out_color;
	float		factor;
	float		bias;

	ft_bzero((float**)bmap, sizeof(float) * (size.y * size.x));
	add_fill_blur_mask((float*)&(bmap[0][0]), size, value);
	factor = 1.0 / 13.0;
	bias = 0.0;
	psrc.y = -1;
	while (++(psrc.y) < WIN_Y && (psrc.x = -1))
	{
		while (++(psrc.x) < WIN_X)
		{
			fcolor = (FColor){0.0, 0.0, 0.0};
			pfilter.y = -1;
			while (++(pfilter.y) < size.y && (pfilter.x = -1))
				while (++(pfilter.x) < size.x)
				{
					pimg.x = (psrc.x - size.x / 2 + pfilter.x + WIN_X) % WIN_X;
					pimg.y = (psrc.y - size.y / 2 + pfilter.y + WIN_Y) % WIN_Y;
					src_color = (SDL_Color){
						src[pimg.y * WIN_X + pimg.x] >> 16,
						(src[pimg.y * WIN_X + pimg.x] >> 8) & 0xff,
						src[pimg.y * WIN_X + pimg.x] & 0xff, 0};
					fcolor = (FColor){
						fcolor.r + src_color.r * bmap[pfilter.y][pfilter.x],
						fcolor.g + src_color.g * bmap[pfilter.y][pfilter.x],
						fcolor.b + src_color.b * bmap[pfilter.y][pfilter.x]};
				}
			out_color.r = MIN(MAX((int)(factor * fcolor.r + bias), 0), 255);
			out_color.g = MIN(MAX((int)(factor * fcolor.g + bias), 0), 255);
			out_color.b = MIN(MAX((int)(factor * fcolor.b + bias), 0), 255);
			src[psrc.y * WIN_X + psrc.x] = (out_color.r << 16 |
				out_color.g << 8 | out_color.b);
		}
	}
}
