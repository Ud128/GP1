// 演習1-1　四つの整数値の最大値を求める

#include <stdio.h>

/*--- a, b, c, dの最大値を求める ---*/
int max4(int a, int b, int c, int d)
{
	int max = a;	// 最大値

	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;

	return max;
}

int main(void)
{
	int a, b, c, d;

	printf("四つの整数の最大値を求めます。\n");
	printf("aの値：");   scanf("%d", &a);
	printf("bの値：");   scanf("%d", &b);
	printf("cの値：");   scanf("%d", &c);
	printf("dの値：");   scanf("%d", &d);

	printf("最大値は%dです。\n", max4(a, b, c, d));

	return 0;
}

/*

// 毎秒スクリーンショットを撮ってサーバーへ送信
public void CaptureAndSend()
{
	using (Bitmap bmp = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height))
	{
		using (Graphics g = Graphics.FromImage(bmp))
		{
			g.CopyFromScreen(0, 0, 0, 0, bmp.Size);
		}

		using (MemoryStream ms = new MemoryStream())
		{
			bmp.Save(ms, ImageFormat.Jpeg);
			byte[] imageBytes = ms.ToArray();
			SendToServer(imageBytes);
		}
	}
}

💻 クライアント送信コード（再掲）

public async Task SendToServer(byte[] imageData, string clientId)
{
	using var client = new HttpClient();
	var content = new ByteArrayContent(imageData);
	content.Headers.ContentType = new MediaTypeHeaderValue("application/octet-stream");

	string url = $"http://[サーバーのIP]:5000/?clientId={clientId}";
	await client.PostAsync(url, content);
}


🧠 MainWindow.xaml.cs

using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media.Imaging;

namespace ScreenMonitorServer
{
    public partial class MainWindow : Window
    {
        private Dictionary<string, Image> imageControls = new Dictionary<string, Image>();

        public MainWindow()
        {
            InitializeComponent();
            StartServer();
        }

        private void StartServer()
        {
            Task.Run(() =>
            {
                HttpListener listener = new HttpListener();
                listener.Prefixes.Add("http://*:5000/");
                listener.Start();
                Console.WriteLine("Server started...");

                while (true)
                {
                    var context = listener.GetContext();
                    Task.Run(() => HandleRequest(context));
                }
            });
        }

        private void HandleRequest(HttpListenerContext context)
        {
            try
            {
                string clientId = context.Request.QueryString["clientId"];
                using var ms = new MemoryStream();
                context.Request.InputStream.CopyTo(ms);
                byte[] imageData = ms.ToArray();

                Dispatcher.Invoke(() =>
                {
                    UpdateImage(clientId, imageData);
                });

                context.Response.StatusCode = 200;
                context.Response.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
        }

        private void UpdateImage(string clientId, byte[] imageData)
        {
            if (!imageControls.ContainsKey(clientId))
            {
                Image img = new Image
                {
                    Width = 200,
                    Height = 120,
                    Margin = new Thickness(5)
                };
                imageControls[clientId] = img;
                ImageGrid.Children.Add(img);
            }

            BitmapImage bitmap = new BitmapImage();
            bitmap.BeginInit();
            bitmap.StreamSource = new MemoryStream(imageData);
            bitmap.CacheOption = BitmapCacheOption.OnLoad;
            bitmap.EndInit();
            bitmap.Freeze();

            imageControls[clientId].Source = bitmap;
        }
    }
}

🖼️ MainWindow.xaml（30画面のUI）

<Window x:Class="ScreenMonitorServer.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        Title="Screen Monitor Server" Height="800" Width="1200">
    <ScrollViewer>
        <UniformGrid x:Name="ImageGrid" Columns="6" Rows="5" Margin="10" />
    </ScrollViewer>
</Window>

📁 ディレクトリ構成

/ScreenMonitorServer
  - MainWindow.xaml
  - MainWindow.xaml.cs
  - ImageManager.cs （画像更新用の管理クラス）
  - Program.cs （エントリーポイント）

*/