#ifndef LIMITSIDE_HPP
# define LIMITSIDE_HPP
# include "../../core/AComponent.hpp"
# include "../../utils/vec.hpp"

class LimitSide : public AComponent
{
public:
	// LimitSide( void );
	LimitSide( Vec2i const & a, Vec2i const & b);
	~LimitSide( void );
	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;

	void						setPos2(Vec2i pos);
	Vec2i						getPos2(void);

private:
	Vec2i	_pos2;
};

#endif
