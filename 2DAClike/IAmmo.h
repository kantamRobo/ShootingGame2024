#include <DxLib.h>
#include "Circle.h"
class IAmmo
{
public:
    IAmmo() : position(VGet(0, 0, 0)), isActive(false) {};


    VECTOR GetPosition() const { return position; }
    void SetPosition(const VECTOR& pos) { position = pos; }

    bool GetIsActive() const { return isActive; }
    void SetIsActive(bool active) { isActive = active; }
    bool isDirty = false;

    IAmmo(const VECTOR& pos);

    void Draw();

    virtual void Update(const float AMMOVELOCITY, const VECTOR& objectpos, float objectangle) = 0;

protected:

    VECTOR position;
    bool isActive;
    float AMMOVELOCITY;

};
