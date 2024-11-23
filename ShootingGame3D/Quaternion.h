#pragma once
#include <DxLib.h>
#include <math.h>


typedef struct Quaternion
{
	double t;//real
	double x;//x
	double y;//y
	double z;//z

    void Set(VECTOR translate, MATRIX& matRot)
    {
        MATRIX mat;
        
        MATRIX matTrans;
        float yaw, pitch, roll;
        yaw = pitch = roll = 0.0f;

        VECTOR xAxis, yAxis, zAxis;

        Quaternion quaternion;  //クォータニオン定義
        quaternion.x = quaternion.y = quaternion.z = 0.0f;
        quaternion.t = 1.0f;

        //ロール
        zAxis = VGet(mat.m[2][0], mat.m[2][1], mat.m[2][2]);
        quaternion = quaternion * CreateRotationQuaternion(roll, zAxis);
        //ピッチ
        xAxis = VGet(mat.m[0][0], mat.m[0][1], mat.m[0][2]);
        quaternion = quaternion * CreateRotationQuaternion(pitch, xAxis);
        //ヨー
        yAxis = VGet(mat.m[1][0], mat.m[1][1], mat.m[1][2]);
        quaternion = quaternion * CreateRotationQuaternion(yaw, yAxis);

        matRot = QuaternionToMatrix(quaternion);
        
       

       
       

      
        //カメラの行列に回転行列を乗算する


       // MV1DrawModel(modelhandle);

    }



    //回転クォータニオン
    Quaternion CreateRotationQuaternion(double radian, VECTOR Axis)
    {
        Quaternion ans;
        double norm;
        double ccc, sss;

        ans.t = ans.x = ans.y = ans.z = 0.0;

        norm = Axis.x * Axis.x + Axis.y * Axis.y + Axis.z * Axis.z;

        if (norm < 0.0001)
        {
            return ans;
        }

        norm = 1.0f / sqrt(norm);
        Axis.x *= norm;
        Axis.y *= norm;
        Axis.z *= norm;

        ccc = cos(radian / 2);
        sss = sin(radian / 2);

        ans.t = ccc;
        ans.x = sss * Axis.x;
        ans.y = sss * Axis.y;
        ans.z = sss * Axis.z;

        return ans;
    }

    //位置クォータニオン
    Quaternion CreateXYZToQuaternion(double PosX, double PosY, double PosZ)
    {
        Quaternion ans;

        ans.t = 0.0;
        ans.x = PosX;
        ans.y = PosY;
        ans.z = PosZ;

        return ans;
    }

    //クォータニオンから回転行列へ
    MATRIX QuaternionToMatrix(Quaternion q)
    {
        MATRIX mat = MGetIdent();
        //X軸
        mat.m[0][0] = 1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z;
        mat.m[0][1] = 2.0f * q.x * q.y + 2.0f * q.t * q.z;
        mat.m[0][2] = 2.0f * q.x * q.z - 2.0f * q.t * q.y;

        //Y軸
        mat.m[1][0] = 2.0f * q.x * q.y - 2.0f * q.t * q.z;
        mat.m[1][1] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z;
        mat.m[1][2] = 2.0f * q.y * q.z + 2.0f * q.t * q.x;

        //Z軸
        mat.m[2][0] = 2.0f * q.x * q.z + 2.0f * q.t * q.y;
        mat.m[2][1] = 2.0f * q.y * q.z - 2.0f * q.t * q.x;
        mat.m[2][2] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y;

        return mat;
    }



}Quaternion;

//クォータニオンの計算
Quaternion operator*(Quaternion q1, Quaternion q2)
{
    Quaternion ans;
    double d1, d2, d3, d4;



    //tパラメータの計算
    d1 = q1.t * q2.t;
    d2 = -q1.x * q2.x;
    d3 = -q1.y * q2.y;
    d4 = -q1.z * q2.z;
    ans.t = d1 + d2 + d3 + d4;

    //xパラメータの計算
    d1 = q1.t * q2.x;
    d2 = q2.t * q1.x;
    d3 = q1.y * q2.z;
    d4 = -q1.z * q2.y;
    ans.x = d1 + d2 + d3 + d4;

    //yパラメータの計算
    d1 = q1.t * q2.y;
    d2 = q2.t * q1.y;
    d3 = q1.z * q2.x;
    d4 = -q1.x * q2.z;
    ans.y = d1 + d2 + d3 + d4;

    //zパラメータの計算
    d1 = q1.t * q2.z;
    d2 = q2.t * q1.z;
    d3 = q1.x * q2.y;
    d4 = -q1.y * q2.x;
    ans.z = d1 + d2 + d3 + d4;

    return ans;
}