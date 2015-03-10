#ifndef WALL_HPP
# define WALL_HPP
# include "../../core/AComponent.hpp"
# include "../../utils/vec.hpp"

class Wall : public AComponent
{
public:
	// Wall( void );
	Wall( Vec2i const & a, Vec2i const & b);
	~Wall( void );
	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;

	void						setPos2(Vec2i pos);
	Vec2i						getPos2(void);

private:
	Vec2i	_pos2;
};

#endif
