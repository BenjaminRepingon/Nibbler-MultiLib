
#include "Wall.hpp"

#warning "TODO: copilian form for Wall"
Wall::Wall( float x1, float y1, float x2, float y2 )
{
	static int t = 0;

	srand(t++);
	if (t % 2)
	{
		int save = (int)(rand()%(int)(x2-x1 + 1) + x1);
		setPos( Vec2i( save, (int)(rand()%(int)(y2-y1 + 1) + y1) ) );
		setPos2( Vec2i( save, (int)(rand()%(int)(y2-y1 + 1) + y1) ) );
	}
	else
	{
		int save = (int)(rand()%(int)(y2-y1 + 1) + y1);
		setPos( Vec2i( (int)(rand()%(int)(x2-x1 + 1) + x1), save ) );
		setPos2( Vec2i( (int)(rand()%(int)(x2-x1 + 1) + x1), save ) );
	}
	return ;
}

Wall::~Wall( void )
{
	return ;
}

int			Wall::update( ILib const * lib, double delta )
{
	(void)lib;
	(void)delta;
	return ( true );
}

int			Wall::render( ILib const * lib ) const
{
	lib->drawLine( this->_pos.getX(), this->_pos.getY(), this->_pos2.getX(), this->_pos2.getY() );
	return ( true );
}

void		Wall::setPos2( Vec2i pos2 )
{
	this->_pos2 = pos2;
	return ;
}

Vec2i		Wall::getPos2(void)
{
	return this->_pos2;
}
