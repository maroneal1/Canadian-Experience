/**
* \file Picture.h
*
* \author Alexandria MArone 
*
* Class that provides a view windows for actors.
*/
#pragma once
#include <vector>
#include "Actor.h"
class CPictureObserver; 
class CActor;
/**
* the picture
*
* Lots of picture drawables
*/

class CPicture
{
public:
	/** Default constuctor
	*/
	CPicture();
	/**Destuctor
	*/
	virtual ~CPicture();
	/// Copy Constructor (Disabled)
	CPicture(const CPicture &) = delete;
	/// Assignment Operator (Disabled)
	CPicture &operator=(const CPicture &) = delete;
	/** The picture size
	* \returns Size */
	Gdiplus::Size GetSize() { return mSize; }

	/** The picture size
	* \param size The new picture size */
	void SetSize(Gdiplus::Size size) { mSize = size; }

	/** adds new observer
	* \param observer thing to add */
	void AddObserver(CPictureObserver *observer);

	/** removes observer
	* \param observer  */
	void RemoveObserver(CPictureObserver *observer);

	/** Updates*/
	void UpdateObservers();

	/** \brief draws
	* \param graphics to draw
	*/
	void Draw(Gdiplus::Graphics *graphics);
	/** \brief adds that actor
	* \param actor to add
	*/
	void AddActor(std::shared_ptr<CActor> actor){ mActors.push_back(actor); actor->SetPicture(this); }
	
private:
	/// The observers of this picture
	std::vector<CPictureObserver *> mObservers;
	///The collection of actors
	std::vector<std::shared_ptr<CActor>> mActors;
	/// The picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);

public:
	/**
	* the picture iterator
	*
	* part of step
	*/
	class ActorIter
	{
	public:

		/** i++++
		* \returns actoriter obj */
		const ActorIter& operator++()
		{
			mPos++;
			return *this;
		}
		/** 
		* \param picture 
		* \param pos position
		*/
		ActorIter(CPicture* picture, int pos) : mPicture(picture), mPos(pos) {}

		/**  more cons
		* \returns mpos of actor  */
		std::shared_ptr<CActor> operator *() const 
		{
			return mPicture->mActors[mPos];
		}

		/** not eq op
		* \param other is the itr
		* \returns bool !=
		*/
		bool operator!=(const ActorIter &other) const
		{
			return mPos != other.mPos;
		}



	private:
		int mPos; ///position of m
		CPicture* mPicture; ///picture
		
	};

	/** begin
	* \returns beginning*/
	ActorIter begin() { return ActorIter(this, 0); }
	/** end collection
	* \returns ending */
	ActorIter end() { return ActorIter(this, mActors.size()); }
};

