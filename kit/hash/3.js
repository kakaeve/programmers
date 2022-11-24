function solution(genres, plays) {
    var answer = [];

    let pick = [];
    let position = [];
    let count = [];
    let sum = [];
    
    for(let i=0;i<genres.length;i++){
        if(!pick.includes(genres[i])){
            pick.push(genres[i]);
            count.push([plays[i],-1]);
            position.push([i,-1]);
        }
        else{
            let idx = pick.indexOf(genres[i]);
            if(count[idx][0]<plays[i]){
                count[idx][1] = count[idx][0];
                position[idx][1] = position[idx][0];
                count[idx][0] = plays[i];
                position[idx][0] = i;
            }
            else if(count[idx][1]<plays[i]){
                count[idx][1] = plays[i];
                position[idx][1] = i;
            }
        }
    }
    /*
    console.log('count: ' + count);
    console.log(count);
    console.log('position: ' + position);
    console.log(position);*/
    
    for(let i=0;i<count.length;i++){
        sum.push(count[i][0] + count[i][1]);
    }

    while(sum.length>0){
        let num = sum.indexOf(Math.max.apply(null,sum));

        answer.push(position[num][0]);
        if(count[num][1]!=-1){
            answer.push(position[num][1]);
        }
        count.splice(num,1);
        position.splice(num,1);
        sum.splice(num,1);
    }

    return answer;
}

let genres = ["classic", "pop", "classic", "classic", "pop"];
let plays = [500, 600, 150, 800, 2500];

//console.log(solution(genres, plays));

genres = ["classic", "pop", "classic"];
plays = [500, 600, 150];

//console.log(solution(genres, plays));

genres = ["classic", "pop", "classic", "classic", "pop"];
plays = [11500, 600, 150, 0, 2500];

console.log(solution(genres, plays));


/*

function solution(genres, plays) {
    var answer = [];

    let pick = [];
    let position = [];
    let count = [];
    let sum = [];
    const TRACK_NUM = 2;

    for (let i = 0; i < plays.length; i++) {
        //console.log(pick.includes(genres[i]));
        if (!pick.includes(genres[i])) {
            pick.push(genres[i]);
            position.push([i,-1]);
            count.push([plays[i],-1]);
        }
        else {
            let idx = pick.indexOf(genres[i]) * TRACK_NUM;
            if(count[idx][0]<plays[i]){
                if(count[idx][0] === -1){
                    position[idx][0] = i;
                    count[idx][0] = plays[i];
                }
                else{
                    if(count[idx])
                }
            }
            if (count[num] < plays[i]) {
                if (count[num] == -1) {
                    position[num] = i;
                    count[num] = plays[i];
                }
                else{
                    position[num + 1] = position[num];
                    count[num + 1] = count[num];
                    position[num] = i;
                    count[num] = plays[i];
                }
                //console.log('count[num]: ' + count[num]);
                //console.log('plays[i]: ' + plays[i]);

            }
            else if (count[num + 1] < plays[i]) {
                //console.log(11111);
                //console.log('count[num+1]: ' + count[num + 1]);
                //console.log('plays[i]: ' + plays[i]);

                position[num + 1] = i;
                count[num + 1] = plays[i];
            }

            // for (let j = TRACK_NUM - 1; j >= 0; j--) {
            //     let num = pick.indexOf(genres[i]) * TRACK_NUM - j;
            //     console.log(num);
            //     if (count[num] < plays[i]) {
            //         position[num] = i;
            //         count[num] = plays[i];
            //     }
            // }
        }
    }
    for(let i=0;i<count.length/2;i++){
        sum.push(count[i]+count[i+1]);
    }
    console.log(sum);


    while (sum.length > 0) {
        //console.log(count);
        let num = sum.indexOf(Math.max.apply(null, sum))*2;
        console.log("num: " + num);

        if (count[num] != 0) {
            answer.push(position[num]);
            //console.log(count);
            //console.log(position);
            count.splice(num, 1);
            position.splice(num, 1);

            if (count[num] !== 0) {
                answer.push(position[num]);
                count.splice(num, 1);
                position.splice(num, 1);
            }

            //console.log(count);
            //console.log(position);
            sum.splice(num/2);

        }
        //console.log(count);
    }


    return answer;
}

let genres = ["classic", "pop", "classic", "classic", "pop"];
let plays = [500, 600, 150, 800, 2500];

console.log(solution(genres, plays));

genres = ["classic", "pop", "classic"];
plays = [500, 600, 150];

console.log(solution(genres, plays));
*/