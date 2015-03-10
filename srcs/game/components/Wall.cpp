
#include "Wall.hpp"

#warning "TODO: copilian form for Wall"
Wall::Wall( Vec2i const & a, Vec2i const & b )
{
	setPos( a );
	setPos2( b );
	return ;
}

Wall::~Wall( void )
{
	return ;
}

int			Wall::update( ILib const * lib, double delta )
{
			printf("PDATE DIS SHIT");


	(void)lib;
	(void)delta;
	return ( true );
}

int			Wall::render( ILib const * lib ) const
{
		printf("DRAW DIS SHIT");

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
