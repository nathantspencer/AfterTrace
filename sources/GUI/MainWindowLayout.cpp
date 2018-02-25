#include "MainWindowLayout.h"

#include "GUI/Window/AdjustmentWindow.h"
#include "GUI/Window/DataWindow.h"
#include "GUI/Window/RenderOptionsWindow.h"
#include "GUI/Window/RenderWindow.h"

MainWindowLayout::MainWindowLayout(GLFWwindow* glfwWindow) :
    IWindowLayout(glfwWindow),
    m_mainMenuBar()
{
    std::map<std::string, std::shared_ptr<IWindow> > windows = GetWindows();
    
    int windowFlags = 0;
    windowFlags |= ImGuiWindowFlags_NoResize;
    windowFlags |= ImGuiWindowFlags_NoMove;
    windowFlags |= ImGuiWindowFlags_NoCollapse;
    windowFlags |= ImGuiWindowFlags_ShowBorders;
    
    std::shared_ptr<IWindow> adjustmentWindow = std::make_shared<AdjustmentWindow>(glfwWindow);
    adjustmentWindow->SetFlags(windowFlags);
    windows["Adjustment"] = adjustmentWindow;
    
    std::shared_ptr<IWindow> dataWindow = std::make_shared<DataWindow>(glfwWindow);
    dataWindow->SetFlags(windowFlags);
    windows["Data"] = dataWindow;
    
    std::shared_ptr<IWindow> renderWindow = std::make_shared<RenderWindow>(glfwWindow);
    renderWindow->SetFlags(windowFlags);
    windows["Render"] = renderWindow;
    
    std::shared_ptr<IWindow> renderOptionsWindow = std::make_shared<RenderOptionsWindow>(glfwWindow);
    renderOptionsWindow->SetFlags(windowFlags);
    windows["RenderOptions"] = renderOptionsWindow;
    
    SetWindows(windows);
}

MainWindowLayout::~MainWindowLayout()
{
}

void MainWindowLayout::Update(float deltaSeconds)
{
    std::map<std::string, std::shared_ptr<IWindow> > windows = GetWindows();
    StylePainter* stylePainter = GetStylePainter();
    
    stylePainter->PaintMainMenuBar();
    m_mainMenuBar.Update(deltaSeconds);
    
    stylePainter->PaintAdjustmentWindow();
    windows["Adjustment"]->Update(deltaSeconds);
    
    stylePainter->PaintDataWindow();
    windows["Data"]->Update(deltaSeconds);
    
    stylePainter->PaintRenderWindow();
    windows["Render"]->Update(deltaSeconds);
    
    stylePainter->PaintRenderOptionsWindow();
    windows["RenderOptions"]->Update(deltaSeconds);
}
