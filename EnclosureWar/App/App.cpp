#include "App.h"

App::App()
{
    model = QSharedPointer<Model>::create();
    view_model = QSharedPointer<ViewModel>::create(model);
    view_model->Setup_Commands(view_model);
    view = QSharedPointer<View>::create();

    /* 将command绑定到view层 */
    view->set_build_2p_command(view_model->Get_BuildGame2P_Command());
    view->set_build_3p_command(view_model->Get_BuildGame3P_Command());
    view->set_build_4p_command(view_model->Get_BuildGame4P_Command());

    view->set_move_command(view_model->Get_Move_Command());

    view->set_player1_down_command(view_model->Get_Player1_Down_Command());
    view->set_player1_left_command(view_model->Get_Player1_Left_Command());
    view->set_player1_right_command(view_model->Get_Player1_Right_Command());
    view->set_player1_up_command(view_model->Get_Player1_Up_Command());

    view->set_player2_up_command(view_model->Get_Player2_Up_Command());
    view->set_player2_down_command(view_model->Get_Player2_Down_Command());
    view->set_player2_left_command(view_model->Get_Player2_Left_Command());
    view->set_player2_right_command(view_model->Get_Player2_Right_Command());

    view->set_player3_up_command(view_model->Get_Player3_Up_Command());
    view->set_player3_down_command(view_model->Get_Player3_Down_Command());
    view->set_player3_left_command(view_model->Get_Player3_Left_Command());
    view->set_player3_right_command(view_model->Get_Player3_Right_Command());

    view->set_player4_up_command(view_model->Get_Player4_Up_Command());
    view->set_player4_down_command(view_model->Get_Player4_Down_Command());
    view->set_player4_left_command(view_model->Get_Player4_Left_Command());
    view->set_player4_right_command(view_model->Get_Player4_Right_Command());

    // 利用lambda表达式对仿函数进行绑定
    view->set_get_blocks_colors([&](){
        return view_model->GetBlocks();
    });

    // 绑定信号与槽

}

void App::run()
{
    int pnum = view->Get_Person_Num();
    if(pnum == 2) view_model->Get_BuildGame2P_Command()->exec();
    if(pnum == 3) view_model->Get_BuildGame3P_Command()->exec();
    if(pnum == 4) view_model->Get_BuildGame4P_Command()->exec();
    view->show();
}
