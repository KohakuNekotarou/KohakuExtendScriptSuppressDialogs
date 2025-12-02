# InDesign Plug-In

**I'll add various things to ExtendScript.**
<br>**Let's learn the InDesign SDK together.**

We cannot be held responsible for any issues arising from your use of this service.<br>
Please use it at your own risk.<br>

スクリプトでどうしても実現出来ない事がありましたら、C++SDKで可能か試してみます。<br>
ゆる～くPlugIn開発の仕事募集中、お気軽にメール下さい。<br>
kohaku.nekotarou@gmail.com<br>

## extendScript for JavaScript
```
// SuppressDialogs
// When the dialog opens, the default button is pressed and it closes.
// I have implemented IDialogMgr::SetSuppressDialogs in the script.
// Since calling IDialogMgr::SetSuppressDialogs from ScriptProvider inexplicably fails to work,
// I am invoking it using IIdleTask instead.

#targetengine session

// On SuppressDialogs
app.generalPreferences.kessdSuppressDialogsIdleTask(true);

app.idleTasks.add({name:'myTask', sleep:10}).addEventListener(IdleEvent.ON_IDLE, myTask);

function myTask(ev){
    // Remove myTask
    app.idleTasks.itemByName("myTask").remove();

    // Your actions
    // Assuming text is selected
    app.menuActions.itemByID(78082).invoke(); // 新規ページ参照...

    // Off SuppressDialogs
    app.generalPreferences.kessdSuppressDialogsIdleTask(false);
}
```
