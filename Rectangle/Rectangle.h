//Josiah Lovin
// Rectangle.h
/*The Rectangle class represents a rectangle.
  The Rectangle consists of a length and width
  that must be between [1,20]. */
class Rectangle
{
    public:
        //Desc:  constructor to set the length and width
        //Input: length for len and width for wid
        //Pre:   length and width are in the interval [1,20]
        //Post:  this.length=len and this.width=wid
        Rectangle(int len, int wid)
        {
            if(len>1 && len<21)
                length = len;
            if(wid>1 && wid<21)
                width = wid;
        }
        //Desc:  sets the length of this object
        //Input: length for len
        //Pre:   length is in the interval [1,20]
        //Post:  this.length=len
        void setLength(int len)
        {
            if(len>0 && len<21)
                length = len;
            else
                length = 1;
        }
        //Desc:  sets the width of this object
        //Input: width for wid
        //Pre;   width is in the interval [1,20]
        //Post:  this.width=wid
        void setWidth(int wid)
        {
            if(wid>0 && wid<21)
                width = wid;
            else
                width = 1;
        }
        //Desc:   gets length of the rectangle
        //Return: this.length
        int getLength() const
        {
            return length;
        }
        //Desc:   gets width of the rectangle
        //Return: this.width
        int getWidth() const
        {
            return width;
        }
        //Desc:   calculates and gets the perimeter of the rectangle
        //Return: the perimeter of the rectangle
        int perimeter() const
        {
            return 2*(length + width);
        }
        //Desc:   calculates the gets the area of the rectangle
        //Return: the area of the rectangle
        int area() const
        {
            return length*width;
        }
    private:
        //define data members
        int length{1};
        int width{1};
};
