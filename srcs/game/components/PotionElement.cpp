
#include "PotionElement.hpp"

#warning "TODO: copilian form for PotionElement"
PotionElement::PotionElement( Vec2i const & pos )
{
	setPos( pos );
	this->_startFrame = this->getTime();
	return ;
}

PotionElement::~PotionElement( void )
{
	return ;
}

int			PotionElement::update( ILib const * lib, double delta )
{
	this->_endFrame = this->getTime();
	this->_dt = (this->_endFrame - this->_startFrame);
	if (this->_dt >= 5)
	{
		this->_startFrame = this->getTime();
		if (getPos() != Vec2i(-10, -10))
		{
			this->_savePos = getPos();
			setPos(Vec2i(-10, -10));
		}
		else
			setPos(this->_savePos);

	}
	(void)lib;
	(void)delta;
	return ( true );
}

int			PotionElement::render( ILib const * lib ) const
{
	lib->drawSquare( this->_pos.getX(), this->_pos.getY(), 1, 0xFF00FF );
	return ( true );
}

double			PotionElement::getTime( void )
{
	struct timeval		tv;

	gettimeofday( &tv, NULL );
	return ( tv.tv_sec + (double)tv.tv_usec / SECOND );
}