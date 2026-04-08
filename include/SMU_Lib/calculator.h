#pragma once
class PIDController {
private:
    // PID 增益参数
    double kp, ki, kd;
    
    // 状态变量
    double error;
    double lastError;
    double integral;
    double derivative;
    
    // 积分控制逻辑参数
    double startI;      // 积分分离阈值
    double maxIntegral;  // 积分限幅 (Anti-Windup)
    
    // Slew Rate (加速度限制) 参数
    double maxStep;
    double lastOutput;

    // 输出物理限制 (电压或百分比)
    double maxOutput;
    double minOutput;

public:
    /**
     * @brief 构造函数
     * @param p, i, d PID系数
     * @param start_i 积分分离阈值（误差小于此值才开始积分）
     * @param max_i 积分最大值限幅
     * @param slew_step 每轮循环允许的最大速度变化量
     */
    PIDController(double p, double i, double d, double start_i, double max_i, double slew_step);

    // 重置 PID 状态（每次新任务前调用）
    void reset();

    // 计算输出
    double calculate(double currentError);

    // 动态修改增益（用于调试）
    void setGains(double p, double i, double d);
    
    // 设置输出范围限制（默认 -12.0 到 12.0）
    void setOutputLimits(double min, double max);
};