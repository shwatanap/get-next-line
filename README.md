# get-next-line
Write a function that returns a line read from a file descriptor.

# 方針
1. str_listがNULLであればstr_listを初期化する処理を実行する。そうでない場合には、そのstr_listから処理を進める
2. BUFFER_SIZE分だけ読み込みを行う。
3. 読み込んだ文字列に改行文字が含まれない場合は2を繰り返してstr_listを連結させていく。
4. 改行文字が含まれた場合は、それまでのstr_list->textを連結させてそれを返す。
5. str_listを改行文字以降の文字列をtextに保持したもののポインタに置き換える。
