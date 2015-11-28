using UnityEngine;
using System.Collections;
//添加脚本到component菜单
public class followCamera : MonoBehaviour
{
    //摄像机固定在猪脚上方10米高度
    public float camera_height = 10.0f;
    //摄像机离猪脚大概10米的水平距离
    public float camera_distance = 10.0f;
    //摄像机和猪脚的transform属性
    private Transform player;
    private Transform camera;
    // Use this for initialization
    void Start()
    {
        //初始化
        player = GameObject.FindGameObjectWithTag("Player").transform;
        camera = Camera.main.transform;
    }
    // Update is called once per frame
    void Update()
    {
        //看向猪脚
        //camera.LookAt (player);
        //与猪脚的正前方为正前方(只取Y轴的旋转度)
        camera.eulerAngles = new Vector3(camera.eulerAngles.x,
        player.eulerAngles.y,
        camera.eulerAngles.z);
        //获取当前的镜头的Y轴旋转度
        float angle = camera.eulerAngles.y;
        //计算x轴的距离差:
        float deltaX = camera_distance * Mathf.Sin(angle * Mathf.PI / 180);
        float deltaZ = camera_distance * Mathf.Cos(angle * Mathf.PI / 180);
        //每一帧都改变摄像机的高度
        camera.position = new Vector3(player.position.x - deltaX,
        player.position.y + camera_height,
        player.position.z - deltaZ);
        Debug.Log("angle:" + angle + ",deltax:" + deltaX + ",deltaZ:" + deltaZ);
    }
}