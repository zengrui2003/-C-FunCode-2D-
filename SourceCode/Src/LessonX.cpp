/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"
#include "math.h"
////////////////////////////////////////////////////////////////////////////////
//
//
int			g_iGameState		=	2;		// 游戏状态，0 -- 游戏结束等待开始状态；1 -- 按下空格键开始，初始化游戏；2 -- 游戏进行中
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();

int HP=1;
int game=0;
int cnt=0;
int game1=0;
int num1=0;
int num2=0;
int num7=0;
int num8=0;
int win1=0;
int win2=0;
int win3=0;
int win4=0;
int cun=1;
int guan=0;
int level=1;
int suipian=0;
float	fSpeedX=0.f, fSpeedY=0.f;
int g_GameState=0;

//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)

{
    int	IsGameWin();
    // 初始化游戏引擎
    if( !dInitGameEngine( hInstance, lpCmdLine ) )
        return 0;


    // To do : 在此使用API更改窗口标题
    dSetWindowTitle("Lesson");



    // 引擎主循环，处理屏幕图像刷新等工作
    /*if(game==0)
    {
        dLoadMap("kaishi.t2d");

    */
    while( dEngineMainLoop() )
    {
        // 获取两次调用之间的时间差，传递给游戏逻辑处理
        float	fTimeDelta	=	dGetTimeDelta();

        // 执行游戏主循环
        GameMainLoop( fTimeDelta );
    };


    // 关闭游戏引擎
    dShutdownGameEngine();

    return 0;
}

//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态.
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void GameMainLoop( float	fDeltaTime )
{
    switch( g_iGameState )
    {
    // 初始化游戏，清空上一局相关数据
    case 1:
    {
        GameInit();
        g_iGameState	=	2; // 初始化之后，将游戏状态设置为进行中
    }
    break;

    // 游戏进行中，处理各种游戏逻辑
    case 2:
    {
        // TODO 修改此处游戏循环条件，完成正确游戏逻辑
        if( true )
        {
            GameRun( fDeltaTime );
        }
        else
        {
            // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
            g_iGameState	=	0;
            GameEnd();
        }
        if(HP==0)
        {
            HP+=1;
        }
    }
    break;

    // 游戏结束/等待按空格键开始
    case 0:
    default:
        break;
    };
}

//==============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void GameInit()
{
}
//==============================================================================
//
// 每局游戏进行中
void GameRun( float fDeltaTime )
{
    if(HP==0)
    {

        dLoadMap("shibai33.t2d");
        dStopAllSound();//停止音乐
    }

    if(num7==1&&num8==1)
    {
        game1=5;
        num7=0;
        num8=0;
    }
    if(game1==5)
    {
        dSetSpritePosition( "wenzi5",35.861, 34.000);
    }

}
//==============================================================================
//
// 本局游戏结束
void GameEnd()
{
}
//==========================================================================



// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseMove( const float fMouseX, const float fMouseY )
{
    if(dIsPointInSprite("kaishiyouxi",fMouseX,fMouseY))
    {
        dSetSpriteScale("kaishiyouxi",1.3);
    }
    else
    {
        dSetSpriteScale("kaishiyouxi",1);
    }
    if(dIsPointInSprite("youxijieshao",fMouseX,fMouseY))
    {
        dSetSpriteScale("youxijieshao",1.3);
    }
    else
    {
        dSetSpriteScale("youxijieshao",1);
    }
    if(dIsPointInSprite("youxibeijing",fMouseX,fMouseY))
    {
        dSetSpriteScale("youxibeijing",1.3);
    }
    else
    {
        dSetSpriteScale("youxibeijing",1);
    }
}
//==========================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标

void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    if(guan==0)
    {
        if (dIsPointInSprite( "youxijieshao", fMouseX, fMouseY ))//游戏介绍
        {
            dLoadMap("youxijieshao.t2d");
        }
        if (dIsPointInSprite( "youxibeijing", fMouseX, fMouseY ))//游戏背景
        {
            dLoadMap("youxibeijing.t2d");
        }
        if (dIsPointInSprite( "shangyiye", fMouseX, fMouseY ))//上一页
        {
            dLoadMap("kaishi.t2d");
        }
        if (dIsPointInSprite( "back2", fMouseX, fMouseY ))//返回
        {
            dLoadMap("kaishi.t2d");
        }
        if (dIsPointInSprite( "kaishiyouxi", fMouseX, fMouseY ))//开始游戏并加载第一关地图和音乐
        {
            guan=1;
            dLoadMap("migong.t2d");
            dPlaySound("yui.ogg", 1, 1 );
        }
    }
    if (dIsPointInSprite( "xia1", fMouseX, fMouseY )) //点击进行第二关并加载地图和音乐
    {
        dLoadMap("xiangzi.t2d");
        dStopAllSound();//停止音乐
        //dPlaySound("", 1, 1 );//加载新音乐
        guan=2;
    }

    if (dIsPointInSprite( "xia2", fMouseX, fMouseY )) //点击进行第三关并加载地图和音乐
    {
        dLoadMap("paoku.t2d");
        dStopAllSound();//停止音乐
        dPlaySound("tui.ogg", 1, 1 );//加载新音乐

    }

    if (dIsPointInSprite( "chongxin2", fMouseX, fMouseY )) //失败重新开始第三关
    {
        dLoadMap("paoku.t2d");
        dPlaySound("tui.ogg", 1, 1 );
    }
    if (dIsPointInSprite( "xia3", fMouseX, fMouseY )) //第三关过关进入答题页面
    {
        dLoadMap("dati2.t2d");
        dStopAllSound();
    }
    if (dIsPointInSprite( "ti7A", fMouseX, fMouseY )) //选择错误返回第一关重新开始
    {
        dLoadMap("migong.t2d");
        dPlaySound("yui.ogg", 1, 1 );
        win4=0;
    }
    if (dIsPointInSprite( "ti7C", fMouseX, fMouseY ))
    {
        dLoadMap("migong.t2d");
        dPlaySound("yui.ogg", 1, 1 );
        win4=0;
    }

    if (dIsPointInSprite( "ti8B", fMouseX, fMouseY ))
    {
        dLoadMap("migong.t2d");
        dPlaySound("yui.ogg", 1, 1 );
        win4=0;
    }
    if (dIsPointInSprite( "ti8c", fMouseX, fMouseY ))
    {
        dLoadMap("migong.t2d");
       dPlaySound("yui.ogg", 1, 1 );
        win4=0;
    }
    if (dIsPointInSprite( "ti7B", fMouseX, fMouseY ))
    {
        dSetSpritePosition( "great7",-36.164, 13.880);
        num7=1;
    }
    if (dIsPointInSprite( "ti8A", fMouseX, fMouseY )) //两道都选对了将打勾
    {
        dSetSpritePosition( "great8", 5.035, -2.000);
        num8=1;
    }
    if (dIsPointInSprite( "wenzi5", fMouseX, fMouseY ))
    {
        dLoadMap("map5.t2d");
    }
    if (dIsPointInSprite( "jieshu", fMouseX, fMouseY ))
    {
        dLoadMap("kaishi.t2d");
    }
    if (dIsPointInSprite( "hhh", fMouseX, fMouseY ))
    {
        dLoadMap("map6.t2d");
    }
}
//==========================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{

    if(guan==1)//第一关人物精灵移动代码
    {
        if(iKey == KEY_S)
        {
            dSetSpriteLinearVelocity("ren1",0,12);
        }
        if(iKey == KEY_W)
        {
            dSetSpriteLinearVelocity("ren1",0,-12);
        }
        if(iKey == KEY_A)
        {
            dSetSpriteLinearVelocity("ren1",-12,0);
            dSetSpriteFlipX( "ren1",1);

        }
        if(iKey == KEY_D)
        {
            dSetSpriteLinearVelocity("ren1",12,-0);
            dSetSpriteFlipX( "ren1",0);
        }
    }
    if(guan==2) //第二关人物精灵移动代码
    {
        if(iKey == KEY_S)
        {
            dSetSpriteLinearVelocity("ren2",0,20);
        }
        if(iKey == KEY_W)
        {
            dSetSpriteLinearVelocity("ren2",0,-20);
        }
        if(iKey == KEY_A)
        {
            dSetSpriteLinearVelocity("ren2",-20,0);
            dSetSpriteFlipX( "ren2",1);

        }
        if(iKey == KEY_D)
        {
            dSetSpriteLinearVelocity("ren2",20,-0);
            dSetSpriteFlipX( "ren2",0);
        }
    }

    float	fSpeedX=0.f, fSpeedY=0.f;//第三关人物精灵移动代码
    if(iKey==KEY_W)
    {
        dAnimateSpritePlayAnimation( "ren4","fuiaefbAnimation", 1);
        fSpeedY = -80.f;
    }
    if(iKey==KEY_A)
    {
        dSetSpriteFlipX( "ren4",1);
        dAnimateSpritePlayAnimation( "ren4","wAnimation", 1);
        fSpeedX = -30.f;
    }
    if(iKey==KEY_D)
    {
        dSetSpriteFlipX( "ren4",0);
        dAnimateSpritePlayAnimation( "ren4","wAnimation", 1);
        fSpeedX = 30.f;
    }
    dSetSpriteLinearVelocity("ren4", fSpeedX, fSpeedY);
}
//==========================================================================
//
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
void OnKeyUp( const int iKey )
{
    float	fSpeedX, fSpeedY;//当键盘弹起人物精灵停止移动
    switch(iKey)
    {
    case KEY_W:
        if(dGetSpriteLinearVelocityY("ren4")!=0)
            dAnimateSpritePlayAnimation("ren4","mklaefkAnimation", 1);
        dAnimateSpritePlayAnimation( "ren4","fgekafAnimation", 1);
    case KEY_A:
    {
        dAnimateSpritePlayAnimation( "ren4","fgekafAnimation", 1);
        fSpeedX = 0.f;
        fSpeedY = 0.f;
    }
    case KEY_D:
    {
        dAnimateSpritePlayAnimation( "ren4","fgekafAnimation", 1);
        fSpeedX = 0.f;
        fSpeedY = 0.f;
    }
    dSetSpriteLinearVelocity("ren4", fSpeedX, fSpeedY);
    default:
        break;
    }
    if(guan==1)
    {
        if(iKey ==KEY_W)
            dSetSpriteLinearVelocity("ren1", 0, 0);
        if(iKey ==KEY_S)
            dSetSpriteLinearVelocity("ren1", 0, 0);
        if(iKey ==KEY_A)
            dSetSpriteLinearVelocity("ren1", 0, 0);
        if(iKey ==KEY_D)
            dSetSpriteLinearVelocity("ren1", 0, 0);
    }
    if(guan==2)
    {
        if(iKey ==KEY_W)
            dSetSpriteLinearVelocity("ren2", 0, 0);
        if(iKey ==KEY_S)
            dSetSpriteLinearVelocity("ren2", 0, 0);
        if(iKey ==KEY_A)
            dSetSpriteLinearVelocity("ren2", 0, 0);
        if(iKey ==KEY_D)
            dSetSpriteLinearVelocity("ren2", 0, 0);
    }






}
//===========================================================================
//
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
    if(guan==1)
    {
        if(stricmp(szSrcName,"ren1")==0&&stricmp(szTarName,"hongqi1")==0)
        {
            dSetSpritePosition( "xia1", 48.113, 34.327);
        }
    }


    if(stricmp(szSrcName,"ren4")==0&&stricmp(szTarName,"hongqi3")==0)
    {
        dSetSpritePosition( "xia3", 42.876, -30.788);

        cnt+=2;

    }
    if(stricmp(szSrcName,"ren4")==0&&stricmp(szTarName,"ooo")==0)
    {
        dSetSpritePosition( "ren4", 1000, 1000 );
        HP=0;
    }
    if(stricmp(szSrcName,"ren4")==0&&stricmp(szTarName,"map4_21")==0)
    {
        dSetSpriteVisible( "map4_21",0 );
        dSetSpritePosition( "map4_22", 44.520, 8.306 );
    }
}
//===========================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}
