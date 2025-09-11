using System;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace BitLookLite
{
    public partial class BitLookLite : Form
    {
        public BitLookLite()
        {
            InitializeComponent();
        }

        private byte[] fileBytes;
        int count =0;

        private void button1_Click( object sender , EventArgs e )
        {
            OpenFileDialog ofd = new OpenFileDialog();
            if ( ofd.ShowDialog() == DialogResult.OK ) {
                fileBytes = File.ReadAllBytes( ofd.FileName );

                int bytesPerLine = 16;
                int totalLines = (int)Math.Ceiling( (double)fileBytes.Length / bytesPerLine );
                int visibleLines = GetVisibleLineCount();

                vScrollBar1.Minimum = 0;
                vScrollBar1.LargeChange = visibleLines;
                vScrollBar1.SmallChange = 1;
                vScrollBar1.Maximum = totalLines ;

                vScrollBar1.Value = 0;
                DisplayHex( 0 );
            }
        }

        private void vScrollBar1_Scroll( object sender , ScrollEventArgs e )
        {
            if ( fileBytes == null )
                return;

            int bytesPerLine = 16;
            int visibleLines = GetVisibleLineCount();
            int totalLines = (int)Math.Ceiling( (double)fileBytes.Length / bytesPerLine );

            // Valueが最大を超えないように調整
            int value = Math.Min( vScrollBar1.Value , totalLines - visibleLines );
            int offset = value * bytesPerLine;

            DisplayHex( offset );
        }

        private void DisplayHex( int offset )
        {
            if ( fileBytes == null )
                return;

            int bytesPerLine = 16;
            int linesToShow = GetVisibleLineCount();

            // 最後のページの補正（データ末尾も見せる）
            if ( offset + bytesPerLine * linesToShow > fileBytes.Length ) {
                offset = Math.Max( 0 , fileBytes.Length - bytesPerLine * linesToShow );
            }

            int maxOffset = Math.Min( fileBytes.Length , offset + bytesPerLine * linesToShow );

            StringBuilder sb = new StringBuilder();

            for ( int i = offset ; i < maxOffset ; i += bytesPerLine ) {
                sb.Append( $"{i:X8}  " ); // アドレス

                // 16進数部分
                for ( int j = 0 ; j < bytesPerLine ; j++ ) {
                    if ( i + j < fileBytes.Length )
                        sb.Append( $"{fileBytes[i + j]:X2} " );
                    else
                        sb.Append( "   " );
                }

                sb.Append( " " );

                // ASCII部分
                for ( int j = 0 ; j < bytesPerLine ; j++ ) {
                    if ( i + j < fileBytes.Length ) {
                        byte b = fileBytes[i + j];
                        char c = ( b >= 32 && b <= 126 ) ? (char)b : '.';
                        sb.Append( c );
                    }
                    else {
                        sb.Append( ' ' );
                    }
                }

                sb.AppendLine();

            }

            label1.Text = sb.ToString();
        }

        private int GetVisibleLineCount()
        {
            // ラベルの表示行数（ピクセル ÷ フォントの高さ）
            return label1.Height / label1.Font.Height;
        }










        /*
        private byte[] fileBytes;
        int count = 0;

        private void button1_Click( object sender , EventArgs e )
        {
            OpenFileDialog ofd = new OpenFileDialog();
            if ( ofd.ShowDialog() == DialogResult.OK ) {
                fileBytes = File.ReadAllBytes( ofd.FileName );

                int bytesPerLine = 16;
                int linesToShow = GetVisibleLineCount();
                int totalLines = (int)Math.Ceiling( (double)fileBytes.Length / bytesPerLine );

                vScrollBar1.Maximum = Math.Max( 0 , totalLines - linesToShow );
                vScrollBar1.LargeChange = 1;
                vScrollBar1.Value = 0;

                DisplayHex( 0 );
            }
        }

        private void vScrollBar1_Scroll( object sender , ScrollEventArgs e )
        {
            int bytesPerLine = 16;
            int offset = vScrollBar1.Value * bytesPerLine;
            DisplayHex( offset );
        }

        private void DisplayHex( int offset )
        {
            if ( fileBytes == null )
                return;

            count = 0;

            int bytesPerLine = 16;
            int linesToShow = GetVisibleLineCount();
            int maxOffset = Math.Min( fileBytes.Length , offset + bytesPerLine * linesToShow );

            StringBuilder sb = new StringBuilder();

            for ( int i = offset ; i < maxOffset ; i += bytesPerLine ) {
                sb.Append( $"{i:X8}  " );

                for ( int j = 0 ; j < bytesPerLine ; j++ ) {
                    if ( i + j < fileBytes.Length )
                        sb.Append( $"{fileBytes[i + j]:X2} " );
                    else
                        sb.Append( "   " );
                }

                sb.Append( " " );

                for ( int j = 0 ; j < bytesPerLine ; j++ ) {
                    if ( i + j < fileBytes.Length ) {
                        byte b = fileBytes[i + j];
                        char c = ( b >= 32 && b <= 126 ) ? (char)b : '.';
                        sb.Append( c );
                    }
                    else {
                        sb.Append( ' ' );
                    }
                }

                sb.AppendLine();
                count++;
            }


            label1.Text = sb.ToString();
        }

        private int GetVisibleLineCount()
        {
            return label1.Height / label1.Font.Height;
        }
        */

    }
}
