// N皇后可视化Java代码（基于Swing框架）（无需依赖）
// 作者：何沛霖   编写环境：JDK17
import javax.swing.*;
import javax.swing.Timer;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class NQueensVisualization extends JFrame {
    private int n = 8; // 默认皇后数量
    private int animationSpeed = 200; // 动画速度（毫秒）
    private Timer timer;
    private boolean isSolving = false;

    // 算法状态
    private int left = 0, right = 0, cur = 0, all = 0;
    private int currentRow = 0;
    private List<Integer> path = new ArrayList<>();
    private int ans = 0;

    // 用于回溯的状态栈
    private Stack<State> stateStack = new Stack<>();

    // 可视化组件
    private ChessboardPanel chessboardPanel;
    private ControlPanel controlPanel;
    private StatusPanel statusPanel;
    private SolutionPanel solutionPanel;

    // 状态类，用于保存回溯点
    class State {
        int left;
        int right;
        int cur;
        int currentRow;
        int candidate;
        int lastTried;

        State(int left, int right, int cur, int currentRow, int candidate, int lastTried) {
            this.left = left;
            this.right = right;
            this.cur = cur;
            this.currentRow = currentRow;
            this.candidate = candidate;
            this.lastTried = lastTried;
        }
    }

    public NQueensVisualization() {
        setupUI();
        setupTimer();
        initializeAlgorithm();
    }

    private void setupUI() {
        setTitle("N皇后问题可视化");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // 创建主面板（左右分栏）
        JSplitPane mainSplitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT);
        mainSplitPane.setDividerLocation(300);
        mainSplitPane.setResizeWeight(0.3);

        // 左侧控制面板
        JPanel leftPanel = new JPanel(new BorderLayout());
        controlPanel = new ControlPanel();
        statusPanel = new StatusPanel();
        solutionPanel = new SolutionPanel();

        JSplitPane leftSplitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT);
        leftSplitPane.setDividerLocation(200);
        leftSplitPane.setTopComponent(controlPanel);
        leftSplitPane.setBottomComponent(statusPanel);

        leftPanel.add(leftSplitPane, BorderLayout.CENTER);
        leftPanel.add(solutionPanel, BorderLayout.SOUTH);

        mainSplitPane.setLeftComponent(leftPanel);

        // 右侧棋盘面板
        chessboardPanel = new ChessboardPanel();
        mainSplitPane.setRightComponent(chessboardPanel);

        add(mainSplitPane, BorderLayout.CENTER);

        setSize(1000, 700);
        setLocationRelativeTo(null);
    }

    private void setupTimer() {
        timer = new Timer(animationSpeed, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (isSolving) {
                    solveStep();
                }
            }
        });
    }

    private void initializeAlgorithm() {
        left = 0;
        right = 0;
        cur = 0;
        currentRow = 0;
        path.clear();
        ans = 0;
        all = (1 << n) - 1; // 设置所有位为1
        stateStack.clear();
        isSolving = false;

        solutionPanel.clearSolutions();

        updateDisplay();
    }

    // 修正的N皇后回溯算法
    private void solveStep() {
        if (currentRow == n) {
            // 找到一个解
            ans++;
            solutionPanel.addSolution(new ArrayList<>(path));

            if (ans <= 3) {
                // 显示前3个解
                System.out.print("解" + ans + ": ");
                for (int i = 0; i < n; i++) {
                    System.out.print((path.get(i) + 1) + " ");
                }
                System.out.println();
            }

            // 回溯继续寻找其他解
            if (!backtrack()) {
                // 算法结束
                timer.stop();
                isSolving = false;
                controlPanel.setSolvingStatus(false);
                solutionPanel.setTotalSolutions(ans);
                JOptionPane.showMessageDialog(this, "搜索完成！共找到 " + ans + " 个解");
            }
            return;
        }

        // 计算可用位置
        int limit = left | right | cur;
        int candidate = ~limit & all;

        if (candidate == 0) {
            // 没有可用位置，需要回溯
            if (!backtrack()) {
                // 算法结束
                timer.stop();
                isSolving = false;
                controlPanel.setSolvingStatus(false);
                solutionPanel.setTotalSolutions(ans);
                JOptionPane.showMessageDialog(this, "搜索完成！共找到 " + ans + " 个解");
            }
            return;
        }

        // 选择下一个位置（使用lowbit）
        int choose = candidate & -candidate; // lowbit
        int col = Integer.numberOfTrailingZeros(choose);

        // 保存当前状态到栈（用于回溯）
        stateStack.push(new State(left, right, cur, currentRow, candidate, choose));

        // 放置皇后
        path.add(col);

        // 更新攻击范围
        left = (left | choose) << 1;
        right = (right | choose) >> 1;
        cur = cur | choose;
        currentRow++;

        updateDisplay();
    }

    private boolean backtrack() {
        if (stateStack.isEmpty()) {
            return false; // 无法回溯，算法结束
        }

        // 从栈中恢复状态
        State state = stateStack.pop();
        left = state.left;
        right = state.right;
        cur = state.cur;
        currentRow = state.currentRow;
        int candidate = state.candidate;
        int lastTried = state.lastTried;

        // 移除最后一个皇后
        if (!path.isEmpty()) {
            path.remove(path.size() - 1);
        }

        // 尝试下一个候选位置
        candidate &= ~lastTried; // 移除已经尝试过的位置

        if (candidate != 0) {
            // 还有候选位置，选择下一个
            int choose = candidate & -candidate; // lowbit
            int col = Integer.numberOfTrailingZeros(choose);

            // 保存当前状态到栈（用于回溯）
            stateStack.push(new State(left, right, cur, currentRow, candidate, choose));

            // 放置皇后
            path.add(col);

            // 更新攻击范围
            left = (left | choose) << 1;
            right = (right | choose) >> 1;
            cur = cur | choose;
            currentRow++;
        } else {
            // 没有更多候选位置，继续回溯
            return backtrack();
        }

        updateDisplay();
        return true;
    }

    private void updateDisplay() {
        statusPanel.updateStatus(left, right, cur, currentRow, path.size());
        chessboardPanel.setBoardState(path, left, right, cur, currentRow);
        chessboardPanel.repaint();
    }

    // 棋盘面板
    class ChessboardPanel extends JPanel {
        private List<Integer> queens;
        private int leftBits, rightBits, curBits, currentRow;
        private int boardSize;

        public ChessboardPanel() {
            setPreferredSize(new Dimension(600, 600));
            setBorder(BorderFactory.createTitledBorder("棋盘面板"));
            queens = new ArrayList<>();
        }

        public void setBoardState(List<Integer> queens, int left, int right, int cur, int currentRow) {
            this.queens = new ArrayList<>(queens);
            this.leftBits = left;
            this.rightBits = right;
            this.curBits = cur;
            this.currentRow = currentRow;
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g;
            g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            boardSize = Math.min(getWidth(), getHeight()) - 40;
            int cellSize = boardSize / n;
            int offsetX = (getWidth() - boardSize) / 2;
            int offsetY = (getHeight() - boardSize) / 2;

            // 绘制棋盘
            drawChessboard(g2d, offsetX, offsetY, cellSize);

            // 绘制攻击范围
            drawAttackRanges(g2d, offsetX, offsetY, cellSize);

            // 绘制皇后
            drawQueens(g2d, offsetX, offsetY, cellSize);

            // 绘制当前行标记
            drawCurrentRow(g2d, offsetX, offsetY, cellSize);
        }

        private void drawChessboard(Graphics2D g2d, int offsetX, int offsetY, int cellSize) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int x = offsetX + j * cellSize;
                    int y = offsetY + i * cellSize;

                    if ((i + j) % 2 == 0) {
                        g2d.setColor(Color.WHITE);
                    } else {
                        g2d.setColor(new Color(220, 220, 220));
                    }
                    g2d.fillRect(x, y, cellSize, cellSize);

                    g2d.setColor(Color.GRAY);
                    g2d.drawRect(x, y, cellSize, cellSize);

                    // 显示坐标
                    g2d.setColor(Color.BLACK);
                    g2d.setFont(new Font("Arial", Font.PLAIN, 10));
                    g2d.drawString((i+1) + "," + (j+1), x + 2, y + 12);
                }
            }
        }

        private void drawAttackRanges(Graphics2D g2d, int offsetX, int offsetY, int cellSize) {
            // 绘制已放置皇后的攻击范围
            for (int i = 0; i < queens.size(); i++) {
                int row = i;
                int col = queens.get(i);

                int centerX = offsetX + col * cellSize + cellSize / 2;
                int centerY = offsetY + row * cellSize + cellSize / 2;

                // 绘制列攻击线
                g2d.setColor(new Color(255, 0, 0, 100));
                g2d.setStroke(new BasicStroke(2));
                g2d.drawLine(centerX, offsetY, centerX, offsetY + boardSize);

                // 绘制对角线攻击线
                g2d.setColor(new Color(0, 255, 0, 100));
                g2d.drawLine(centerX, centerY, offsetX, centerY + (centerX - offsetX));
                g2d.drawLine(centerX, centerY, offsetX + boardSize, centerY - (offsetX + boardSize - centerX));

                g2d.setColor(new Color(0, 0, 255, 100));
                g2d.drawLine(centerX, centerY, offsetX, centerY - (centerX - offsetX));
                g2d.drawLine(centerX, centerY, offsetX + boardSize, centerY + (offsetX + boardSize - centerX));
            }

            // 绘制当前行的可用位置
            if (currentRow < n) {
                int available = ~(leftBits | rightBits | curBits) & all;
                g2d.setColor(new Color(0, 255, 0, 100));

                for (int col = 0; col < n; col++) {
                    if ((available & (1 << col)) != 0) {
                        int x = offsetX + col * cellSize + cellSize / 2;
                        int y = offsetY + currentRow * cellSize + cellSize / 2;
                        g2d.fillOval(x - 8, y - 8, 16, 16);
                    }
                }
            }
        }

        private void drawQueens(Graphics2D g2d, int offsetX, int offsetY, int cellSize) {
            for (int i = 0; i < queens.size(); i++) {
                int row = i;
                int col = queens.get(i);

                int x = offsetX + col * cellSize;
                int y = offsetY + row * cellSize;

                // 绘制皇后
                g2d.setColor(new Color(255, 215, 0));
                g2d.fillOval(x + 5, y + 5, cellSize - 10, cellSize - 10);

                g2d.setColor(Color.BLACK);
                g2d.drawOval(x + 5, y + 5, cellSize - 10, cellSize - 10);

                // 绘制Q标记
                g2d.setFont(new Font("Arial", Font.BOLD, 12));
                g2d.drawString("Q", x + cellSize/2 - 3, y + cellSize/2 + 3);
            }
        }

        private void drawCurrentRow(Graphics2D g2d, int offsetX, int offsetY, int cellSize) {
            if (currentRow < n) {
                g2d.setColor(new Color(0, 100, 0, 50));
                g2d.fillRect(offsetX, offsetY + currentRow * cellSize,
                        n * cellSize, cellSize);

                g2d.setColor(Color.GREEN);
                g2d.setFont(new Font("Arial", Font.BOLD, 12));
                g2d.drawString("当前行: " + (currentRow + 1),
                        offsetX + 5, offsetY + currentRow * cellSize + 15);
            }
        }
    }

    // 状态显示面板
    class StatusPanel extends JPanel {
        private JLabel leftLabel, rightLabel, curLabel, rowLabel, availableLabel, pathLabel;
        private JTextArea binaryArea;

        public StatusPanel() {
            setLayout(new BorderLayout(5, 5));
            setBorder(BorderFactory.createTitledBorder("二进制状态显示"));

            // 创建状态标签
            JPanel labelPanel = new JPanel(new GridLayout(6, 1, 5, 5));

            leftLabel = new JLabel("left: ");
            rightLabel = new JLabel("right: ");
            curLabel = new JLabel("cur: ");
            rowLabel = new JLabel("当前层数 i: 0");
            availableLabel = new JLabel("可用位置: ");
            pathLabel = new JLabel("当前路径: ");

            labelPanel.add(leftLabel);
            labelPanel.add(rightLabel);
            labelPanel.add(curLabel);
            labelPanel.add(rowLabel);
            labelPanel.add(availableLabel);
            labelPanel.add(pathLabel);

            add(labelPanel, BorderLayout.NORTH);

            // 二进制详细显示
            binaryArea = new JTextArea(10, 20);
            binaryArea.setEditable(false);
            binaryArea.setFont(new Font("Monospaced", Font.PLAIN, 12));
            add(new JScrollPane(binaryArea), BorderLayout.CENTER);
        }

        public void updateStatus(int left, int right, int cur, int currentRow, int pathSize) {
            leftLabel.setText("left: " + formatBinary(left, n));
            rightLabel.setText("right: " + formatBinary(right, n));
            curLabel.setText("cur: " + formatBinary(cur, n));
            rowLabel.setText("当前层数 i: " + currentRow);

            int available = ~(left | right | cur) & all;
            availableLabel.setText("可用位置: " + formatBinary(available, n));
            pathLabel.setText("当前路径长度: " + pathSize);

            // 更新二进制详细显示
            StringBuilder sb = new StringBuilder();
            sb.append("二进制状态详情:\n");
            sb.append("left:  ").append(formatBinary(left, n)).append(" (左对角线攻击)\n");
            sb.append("right: ").append(formatBinary(right, n)).append(" (右对角线攻击)\n");
            sb.append("cur:   ").append(formatBinary(cur, n)).append(" (列攻击)\n\n");

            sb.append("limit = left | right | cur:\n");
            sb.append("       ").append(formatBinary(left | right | cur, n)).append("\n\n");

            sb.append("candidate = ~limit & all:\n");
            sb.append("          ").append(formatBinary(available, n)).append("\n");
            sb.append("(0=被攻击, 1=可用)\n\n");

            sb.append("栈深度: ").append(stateStack.size()).append("\n");

            binaryArea.setText(sb.toString());
        }

        private String formatBinary(int num, int bits) {
            String binary = Integer.toBinaryString(num);
            while (binary.length() < bits) {
                binary = "0" + binary;
            }
            if (binary.length() > bits) {
                binary = binary.substring(binary.length() - bits);
            }
            return binary;
        }
    }

    // 解决方案面板
    class SolutionPanel extends JPanel {
        private JTextArea solutionArea;
        private JLabel totalLabel;
        private int solutionCount = 0;

        public SolutionPanel() {
            setLayout(new BorderLayout());
            setBorder(BorderFactory.createTitledBorder("解决方案"));
            setPreferredSize(new Dimension(280, 150));

            totalLabel = new JLabel("已找到解: 0");
            add(totalLabel, BorderLayout.NORTH);

            solutionArea = new JTextArea(5, 20);
            solutionArea.setEditable(false);
            solutionArea.setFont(new Font("Monospaced", Font.PLAIN, 12));
            add(new JScrollPane(solutionArea), BorderLayout.CENTER);
        }

        public void addSolution(List<Integer> solution) {
            solutionCount++;
            StringBuilder sb = new StringBuilder();
            sb.append("解").append(solutionCount).append(": ");
            for (int i = 0; i < solution.size(); i++) {
                sb.append(solution.get(i) + 1);
                if (i < solution.size() - 1) sb.append(" ");
            }
            solutionArea.append(sb.toString() + "\n");
            totalLabel.setText("已找到解: " + solutionCount);
        }

        public void clearSolutions() {
            solutionCount = 0;
            solutionArea.setText("");
            totalLabel.setText("已找到解: 0");
        }

        public void setTotalSolutions(int total) {
            totalLabel.setText("总共找到解: " + total);
        }
    }

    // 控制面板
    class ControlPanel extends JPanel {
        private JButton startButton, pauseButton, resetButton, stepButton;
        private JSlider speedSlider;
        private JSpinner nSpinner;
        private JLabel statusLabel;

        public ControlPanel() {
            setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
            setBorder(BorderFactory.createTitledBorder("控制面板"));

            // N数量设置
            JPanel nPanel = new JPanel(new FlowLayout());
            nPanel.add(new JLabel("N数量设置:"));
            nSpinner = new JSpinner(new SpinnerNumberModel(n, 1, 16, 1));
            nPanel.add(nSpinner);
            add(nPanel);

            // 速度设置
            JPanel speedPanel = new JPanel(new FlowLayout());
            speedPanel.add(new JLabel("速度设置:"));
            speedSlider = new JSlider(10, 1000, animationSpeed);
            speedSlider.setMajorTickSpacing(200);
            speedSlider.setPaintTicks(true);
            speedSlider.setPaintLabels(true);
            speedPanel.add(speedSlider);
            add(speedPanel);

            // 按钮面板
            JPanel buttonPanel = new JPanel(new GridLayout(2, 2, 5, 5));
            startButton = new JButton("开始求解");
            pauseButton = new JButton("暂停");
            resetButton = new JButton("重置");
            stepButton = new JButton("单步执行");

            pauseButton.setEnabled(false);

            buttonPanel.add(startButton);
            buttonPanel.add(pauseButton);
            buttonPanel.add(resetButton);
            buttonPanel.add(stepButton);

            add(buttonPanel);

            // 状态显示
            statusLabel = new JLabel("就绪");
            statusLabel.setBorder(BorderFactory.createLoweredBevelBorder());
            add(statusLabel);

            setupEventListeners();
        }

        private void setupEventListeners() {
            startButton.addActionListener(e -> startSolving());
            pauseButton.addActionListener(e -> pauseSolving());
            resetButton.addActionListener(e -> resetSolving());
            stepButton.addActionListener(e -> stepSolving());

            speedSlider.addChangeListener(e -> {
                animationSpeed = speedSlider.getValue();
                timer.setDelay(animationSpeed);
            });

            nSpinner.addChangeListener(e -> {
                n = (Integer) nSpinner.getValue();
                resetSolving();
            });
        }

        private void startSolving() {
            isSolving = true;
            setSolvingStatus(true);
            timer.start();
            statusLabel.setText("求解中...");
        }

        private void pauseSolving() {
            isSolving = false;
            setSolvingStatus(false);
            timer.stop();
            statusLabel.setText("已暂停");
        }

        private void resetSolving() {
            timer.stop();
            isSolving = false;
            setSolvingStatus(false);
            initializeAlgorithm();
            statusLabel.setText("已重置");
        }

        private void stepSolving() {
            timer.stop();
            solveStep();
            statusLabel.setText("单步执行");
        }

        public void setSolvingStatus(boolean solving) {
            startButton.setEnabled(!solving);
            pauseButton.setEnabled(solving);
            stepButton.setEnabled(!solving);
            nSpinner.setEnabled(!solving);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            try {
                UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            } catch (Exception e) {
                e.printStackTrace();
            }

            new NQueensVisualization().setVisible(true);
        });
    }
}